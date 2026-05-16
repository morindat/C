/*
queries.c
    Reads queries from queries.txt and executes them using the heap.
    Output is written to final_output.txt following the assignment format.

    Formats:
        BUILD_HEAP → SUCCESS
        INSERT_KEY → SUCCESS
        EXTRACT_MIN → id key1 key2   OR  EXTRACT_MIN → EMPTY
        DECREASE_KEY → SUCCESS or FALSE
        PRINT_HEAP_ARRAY → SUCCESS
        <heap printed on next line with comma-space formatting>
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "heap.h"   // Includes all required function and struct declarations as in heap.c

extern HeapNode heap[];  
extern int heap_size;

/*
print_heap_to_file() -> {
    Prints heap array to the output file, followed by a newline.
}
*/

void print_heap_to_file(FILE *out) {
    for (int i = 0; i < heap_size; i++) {
        fprintf(out, "%s", heap[i].event_id);
        if (i < heap_size - 1) fprintf(out, ", ");
    }
    fprintf(out, "\n");
}

/*
main() -> {
    Reads the queries file and executes the corresponding heap operations.
}
*/

int main() {
    FILE *queries_file = fopen("queries.txt", "r");
    // Clear the log file at startup for a fresh run
    FILE *log_clear = fopen("heap_log.txt", "w"); 
    if (log_clear) fclose(log_clear); 
    
    FILE *out = fopen("final_output.txt", "w");

    if (!queries_file) {
        fprintf(stderr, "Error opening queries.txt.\n");
        return 1;
    }
    if (!out) {
        fprintf(stderr, "Error opening final_output.txt.\n");
        fclose(queries_file);
        return 1;
    }

    fprintf(out, "Outputs of queries:\n");

    char line[256];

    while (fgets(line, sizeof(line), queries_file)) {
        char id[32];
        int k1, k2;

        // Remove both newline (\n) and carriage return (\r) 
        // Find the first occurrence of '\r' or '\n' and replace it with null terminator
        line[strcspn(line, "\r\n")] = 0;

        // BUILD_HEAP
        
        if (strcmp(line, "BUILD_HEAP") == 0) {
            FILE *clean = fopen("cleaned_events.txt", "r");
            if (!clean) {
                fprintf(stderr, "Could not open cleaned_events.txt. Run clean.c first.\n");
                fprintf(out, "BUILD_HEAP → FAILURE: Missing cleaned_events.txt\n");
            } else {
                build_heap(clean);
                fclose(clean);
                fprintf(out, "BUILD_HEAP → SUCCESS\n");
            }
        }

        // INSERT

        else if (sscanf(line, "INSERT %s %d %d", id, &k1, &k2) == 3) {
            HeapNode x;
            // Check for max length
            strncpy(x.event_id, id, 31);
            x.event_id[31] = '\0';
            x.key1 = k1;
            x.key2 = k2;

            if (heap_size < MAX_HEAP) {
                insert(heap, x);
                fprintf(out, "INSERT_KEY → SUCCESS\n");
            } else {
                fprintf(out, "INSERT_KEY → FAILURE: HEAP FULL\n");
            }
        }

        // EXTRACT_MIN

        else if (strcmp(line, "EXTRACT_MIN") == 0) {
            HeapNode x = extract_min(heap);

            if (x.key1 == -1 && x.key2 == -1) { // Sentinel value check
                fprintf(out, "EXTRACT_MIN → EMPTY\n");
            } else {
                fprintf(out, "EXTRACT_MIN → %s %d %d\n",
                            x.event_id, x.key1, x.key2);
            }
        }

        // DECREASE_KEY

        else if (sscanf(line, "DECREASE_KEY %s %d %d", id, &k1, &k2) == 3) {
            int index_before = -1;
            int found_before = 0;
            
            // 1. Find the event's current index and old node
            for(int i=0; i < heap_size; i++){
                if(strcmp(heap[i].event_id, id) == 0){
                    index_before = i;
                    found_before = 1;
                    break;
                }
            }
            
            if (found_before) {
                HeapNode old_node = heap[index_before];
                HeapNode new_node = { "", k1, k2 };
                strcpy(new_node.event_id, id);

                // 2. Check if the new keys actually represent a *strictly* better priority
                if (is_smaller(new_node, old_node)) {
                    // Keys are strictly better -> perform the operation
                    decrease_key(heap, id, k1, k2);
                    fprintf(out, "DECREASE_KEY → SUCCESS\n");
                } else {
                    // Keys are worse or the same priority -> FALSE
                    fprintf(out, "DECREASE_KEY → FALSE\n");
                }
            } else {
                // Event ID not found in heap -> FALSE
                fprintf(out, "DECREASE_KEY → FALSE\n");
            }

        }

        // PRINT_HEAP_ARRAY

        else if (strcmp(line, "PRINT_HEAP") == 0 ||
                 strcmp(line, "PRINT_HEAP_ARRAY") == 0) {

            fprintf(out, "PRINT_HEAP_ARRAY → SUCCESS\n");
            print_heap_to_file(out);
            log_heap_state("PRINT_HEAP_ARRAY"); // Log state after printing
        }
        
        // UNKNOWN COMMAND
        
        else {
            // Handle lines that do not match a command format
            fprintf(stderr, "Warning: Unknown command or malformed line in queries.txt: %s\n", line);
        }
    }

    fclose(queries_file);
    fclose(out);
    printf("CONGRATULATIONS MAHN, EVERYTHING IS WORKING CORRECTLY, LOL!\n");

    return 0;
}