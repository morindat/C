/*
heap.c
    Implements a 2-key min-heap using (key1, key2, event_id) priority.

TODO:
    - Implement the following;
    - Node struct (in heap.h)
    - Utilities functions;
            - log heap state into a heap_log.txt file
            - swap
            - comparison fn (is_smaller)
            - bubble down (min_heapify)
            - bubble up
    - Heap functions;
            - Insert
            - Extract Min
            - Print Heap
            - Decrease Key
            - Build Heap
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "heap.h"   // Includes HeapNode definition and MAX_HEAP

// GLOBAL HEAP STORAGE DEFINITION
HeapNode heap[MAX_HEAP];
int heap_size = 0;
// why do i initialize the coint for heap size instead of just using max heap which is 6000

/*
log_heap_state() -> {
    Appends the current heap state to heap_log.txt.
    The format is:
        OPERATION_NAME
        E10,E3,E7,E2,...
}
*/

void log_heap_state(const char *operation) {
    FILE *fp = fopen("heap_log.txt", "a");
    if (!fp) return;

    fprintf(fp, "%s\n", operation);

    for (int i = 0; i < heap_size; i++) {
        fprintf(fp, "%s", heap[i].event_id);
        if (i < heap_size - 1) fprintf(fp, ", ");
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}


/*
is_smaller(nodeA, nodeB) -> {
    Compares two heap nodes (nodeA < nodeB) according to priority rules.
    Returns 1 if nodeA has STRICTLY HIGHER priority than nodeB.
}
*/

int is_smaller(HeapNode nodeA, HeapNode nodeB) {
    // 1. key1 (smaller wins)
    if (nodeA.key1 != nodeB.key1) return nodeA.key1 < nodeB.key1;
    // 2. key2 (smaller wins)
    if (nodeA.key2 != nodeB.key2) return nodeA.key2 < nodeB.key2;
    // 3. event_id (lexicographically smaller wins)
    return strcmp(nodeA.event_id, nodeB.event_id) < 0;
}


/*
swap() -> {
    Swaps two HeapNode structs. Classic swap fn
}
*/

void swap(HeapNode *nodeA, HeapNode *nodeB) {
    HeapNode temp = *nodeA;
    *nodeA = *nodeB;
    *nodeB = temp;
}

/*
bubble_up() -> {
    Moves a node UP the heap to it's correct position to restore heap property.
}
*/

void bubble_up(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (is_smaller(heap[index], heap[parent])) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break; // Heap property satisfied
        }
    }
}

/*
bubble_down() -> {
    Restores heap property by moving element DOWN the tree (Min-Heapify).
}
*/

void bubble_down(int index) {
    while (1) {
        int left  = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // Check left child
        if (left < heap_size && is_smaller(heap[left], heap[smallest]))
            smallest = left;
        
        // Check right child
        if (right < heap_size && is_smaller(heap[right], heap[smallest]))
            smallest = right;

        if (smallest == index) break; // Heap property satisfied

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}


/*
insert() -> {
    Inserts a new event into the heap.
}
*/

void insert(HeapNode *A, HeapNode x) {
    if (heap_size >= MAX_HEAP) {
        fprintf(stderr, "Error: Heap overflow on insert of %s.\n", x.event_id);
        return;
    }

    A[heap_size] = x;
    bubble_up(heap_size);
    heap_size++;

    char op[128];
    sprintf(op, "INSERT %s %d %d", x.event_id, x.key1, x.key2);
    log_heap_state(op);
}


/*
extract_min() -> {
    Removes and returns the smallest (highest priority) element in the heap.
}
*/

HeapNode extract_min(HeapNode *A) {
    // Empty event used to signal failure/empty heap
    HeapNode empty = { "", -1, -1 }; 

    if (heap_size == 0) {
        return empty;
    }

    HeapNode min = A[0];

    // Move last element to root
    heap_size--;
    if (heap_size > 0) {
        A[0] = A[heap_size];
        // Restore heap property
        bubble_down(0);
    }

    log_heap_state("EXTRACT_MIN");

    return min;
}


/*
decrease_key() -> {
    Finds event by event_id, updates its keys, and bubbles up if keys decreased (priority improved).
}
*/

void decrease_key(HeapNode *A, char event_id[], int newK1, int newK2) {
    for (int index = 0; index < heap_size; index++) {
        if (strcmp(A[index].event_id, event_id) == 0) {
            
            // Critical check: Check if the new keys are SMALLER (higher priority)
            HeapNode new_node = { "", newK1, newK2 };
            strcpy(new_node.event_id, event_id);

            // We use is_smaller(new, old) to check if the new node has STRICTLY higher priority
            if (is_smaller(new_node, A[index])) {
                // Priority improved -> update and bubble up
                A[index].key1 = newK1;
                A[index].key2 = newK2;
                bubble_up(index);

                char op[128];
                sprintf(op, "DECREASE_KEY %s %d %d", event_id, newK1, newK2);
                log_heap_state(op);
            }
            // else: new keys are worse or the same priority, operation is invalid/noop (handled as FALSE in queries.c), hopefully i indeed did this, i can not remember lol
            return;
        }
    }
    // Event not found (handled as FALSE in queries.c)
}


/*
print_heap_array() -> {
    Prints event_ids in level-order (array order) to the output file.
}
*/

void print_heap_array(HeapNode *A, FILE *fp) {
    for (int index = 0; index < heap_size; index++) {
        fprintf(fp, "%s", A[index].event_id);
        if (index < heap_size - 1) fprintf(fp, ", "); // Use comma-space separator
    }
    fprintf(fp, "\n");
}


/*
build_heap() -> {
    Reads cleaned_events.txt from FILE* fp, loads the data into the array, and performs heapify.
}
*/

void build_heap(FILE *fp) {
    char line[128];

    // Reset heap state
    heap_size = 0;
    
    // Read and skip header line
    if (fgets(line, sizeof(line), fp) == NULL) return; 

    // Load data into heap array
    while (fgets(line, sizeof(line), fp)) {
        HeapNode x;
        if (sscanf(line, "%s %d %d", x.event_id, &x.key1, &x.key2) == 3) {
            if (heap_size < MAX_HEAP) {
                heap[heap_size] = x;
                heap_size++;
            } else {
                fprintf(stderr, "Warning: Max heap capacity reached during BUILD_HEAP. Data truncated.\n");
                break;
            }
        }
    }
    
    // Heapify: Start from the last non-leaf node (parent of the last element)
    for (int index = heap_size/2 - 1; index >= 0; index--) {
        bubble_down(index);
    }

    log_heap_state("BUILD_HEAP");
}