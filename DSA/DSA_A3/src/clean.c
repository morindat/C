/*
clean.c
This program reads all raw region log files from the folder "events_raw/",
cleans and fixes corrupted entries, removes duplicates using the given
event ordering rules, sorts the valid events, and outputs a single file:
     cleaned_events.txt

TODO:
The assignment demands the following:
  - Fix missing/invalid key1 or key2 → replace with 9999
  - Ignore entries with missing/empty event_id
  - If multiple entries share the same event_id, keep the "smallest"
    according to (key1, key2, lexicographic event_id)
  - Output must be sorted by (key1, key2, event_id)
  - Raw files are messy, it's crazy, so parsing must be robust.

I guess this is all i need to implement the clean.c program
---------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include "heap.h" 

#define MAX_EVENTS MAX_HEAP 

// Global array to hold all events before deduplication and sorting.
// why? it just makes things easier

HeapNode events[MAX_EVENTS];
int event_count = 0;


// UTILITY FUNCTIONS

/*
trim_newline() -> {
    Removes trailing newline characters.
}
*/

void trim_newline(char *s) {
    int n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[n-1] = '\0';
        n--;
    }
}

/*
starts_with() -> {
    Checks whether 's' begins with 'prefix'.
}
*/

int starts_with(const char *s, const char *prefix) {
    return strncmp(s, prefix, strlen(prefix)) == 0;
}

/*
is_valid_integer() -> {
    Validates that a string is a valid signed integer.
}
*/

int is_valid_integer(const char *s) {
    if (s == NULL || *s == '\0') return 0;
    
    int i = 0;
    // Allow leading sign
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }

    // Must have at least one digit
    if (s[i] == '\0') return 0;

    for (; s[i]; i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

/*
parse_int() -> {
    Validates and converts string to int, replacing invalid/missing ones with 9999.
}
*/

int parse_int(const char *s) {
    if (s == NULL || strlen(s) == 0) return 9999;
    
    // Create a mutable copy and trim any leading/trailing whitespace 
    char temp_s[64];
    strncpy(temp_s, s, 63);
    temp_s[63] = '\0';

    char *start = temp_s;
    while(isspace((unsigned char)*start)) start++;
    char *end = start + strlen(start) - 1;
    while(end >= start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    
    if (!is_valid_integer(start)) return 9999;
    
    // Check for overflow before conversion, just makes the code robust, no other particular reason
    long val = strtol(start, NULL, 10);
    if (val > 2147483647L || val < -2147483648L) return 9999; 

    return (int)val;
}

/*
find_duplicate_index() -> {
    Searches the events[] array for a duplicate event_id and returns the index.
}
*/

int find_duplicate_index(const char *event_id) {
    for (int i = 0; i < event_count; i++) {
        if (strcmp(events[i].event_id, event_id) == 0)
            return i;
    }
    return -1;
}

/*
event_to_keep() -> {
    Decides which event (newE or oldE) is smaller (better to keep).
    Returns 1 if newE has higher priority (is smaller) than oldE.
}
*/

int event_to_keep(HeapNode newE, HeapNode oldE) {
    // This uses the same priority logic as is_smaller in heap.c
    if (newE.key1 != oldE.key1)
        return newE.key1 < oldE.key1;
    if (newE.key2 != oldE.key2)
        return newE.key2 < oldE.key2;
    // Lexicographically smaller ID wins
    return strcmp(newE.event_id, oldE.event_id) < 0;
}

/*
add_or_update_event() -> {
    Adds a new event or updates an existing duplicate using the priority rule.
}
*/

void add_or_update_event(HeapNode e) {
    int idx = find_duplicate_index(e.event_id);

    if (idx == -1) {
        // New event: add to array, checking bounds
        if (event_count < MAX_EVENTS) {
            events[event_count++] = e;
        } else {
            fprintf(stderr, "Warning: Max event capacity reached. Dropping event %s.\n", e.event_id);
        }
    } else {
        // Duplicate: keep the one with the smallest keys/id (highest priority).
        if (event_to_keep(e, events[idx])) {
            events[idx] = e;
        }
    }
}

/*
extract_fields() -> {
    Extracts id, key1, key2 from a messy raw line.
}
*/

void extract_fields(char *line, char *id, char *key1, char *key2) {
    id[0] = key1[0] = key2[0] = '\0'; // default: empty

    char *token = strtok(line, ",");
    while (token) {
        // Trim leading/trailing whitespace from the token
        char *start = token;
        while(isspace((unsigned char)*start)) start++;
        
        if (starts_with(start, "id=")) {
            // Copy the value after "id="
            strncpy(id, start + 3, 31);
            id[31] = '\0';
        } else if (starts_with(start, "key1=")) {
            strncpy(key1, start + 5, 31);
            key1[31] = '\0';
        } else if (starts_with(start, "key2=")) {
            strncpy(key2, start + 5, 31);
            key2[31] = '\0';
        }

        token = strtok(NULL, ",");
    }
}

/*
parse_line() -> {
    Takes a raw line, extracts fields, cleans them, applies rules, and inserts.
}
*/

void parse_line(char *line) {
    char id_str[64], k1_str[64], k2_str[64];

    // Extract id/key1/key2 from a line
    extract_fields(line, id_str, k1_str, k2_str);

    // Rule: discard if event_id missing or empty
    if (strlen(id_str) == 0)
        return;

    // Construct cleaned event
    HeapNode e;
    // Ensure event_id is properly copied and null-terminated
    strncpy(e.event_id, id_str, 31);
    e.event_id[31] = '\0'; 
    
    // Parse keys, applying 9999 fix for invalid/missing
    e.key1 = parse_int(k1_str); 
    e.key2 = parse_int(k2_str);

    // Add the event or update existing duplicate
    add_or_update_event(e);
}

// FILE PROCESSING

/*
process_file() -> {
    Reads one raw region log file line-by-line, cleaning every entry.
}
*/

void process_file(const char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Warning: Could not open file: %s\n", filepath);
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        trim_newline(line);
        if (strlen(line) == 0) continue; // ignore empty lines

        char tmp[256];
        strcpy(tmp, line);

        parse_line(tmp);
    }

    fclose(fp);
}

/*
process_all_logs() -> {
    Scans events_raw/ directory for regional files and processes each one.
}
*/

void process_all_logs() {
    DIR *d = opendir("events_raw");
    if (!d) {
        fprintf(stderr, "Cannot open events_raw folder (expected 'events_raw/' or 'events_raw/').\n");
        exit(1);
    }

    struct dirent *ent;
    while ((ent = readdir(d)) != NULL) {

        // Only process files matching region_*_log.txt only
        if (strstr(ent->d_name, "region_") &&
            strstr(ent->d_name, "_log.txt")) {

            char path[512];
            snprintf(path, sizeof(path), "events_raw/%s", ent->d_name);
            process_file(path);
        }
    }

    closedir(d);
}


/*
cmp_event() -> {
    Sorting comparator used by qsort.
    Ensures final output is sorted by (key1, key2, event_id).
}
*/

int cmp_event(const void *a, const void *b) {
    // Cast to HeapNode* for consistency
    const HeapNode *A = a;
    const HeapNode *B = b;

    if (A->key1 != B->key1) return A->key1 - B->key1;
    if (A->key2 != B->key2) return A->key2 - B->key2;
    return strcmp(A->event_id, B->event_id);
}

/*
finalize_and_write_output() -> {
    Performs final sorting and writes cleaned_events.txt exactly as specified.
}
*/

void finalize_and_write_output() {
    qsort(events, event_count, sizeof(HeapNode), cmp_event);

    FILE *fp = fopen("cleaned_events.txt", "w");
    if (!fp) {
        printf("Cannot write cleaned_events.txt\n");
        exit(1);
    }

    fprintf(fp, "event_id key1 key2\n"); 

    for (int i = 0; i < event_count; i++) {
        fprintf(fp, "%s %d %d\n",
                events[i].event_id,
                events[i].key1,
                events[i].key2);
    }

    fclose(fp);
}

// MAIN

/*
main() -> {
    Entry point for the cleaning program.
}
*/

int main() {
    printf("Starting data cleaning and deduplication...\n");
    process_all_logs();
    printf("Cleaning finished. Total unique events: %d\n", event_count);
    finalize_and_write_output();
    printf("Output written to cleaned_events.txt\n");
    return 0;
}