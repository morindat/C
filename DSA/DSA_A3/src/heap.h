/*
heap.h
    Defines the HeapNode structure and declares global variables and functions
    for the Min-Heap implementation.
*/

#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>

// Define MAX_HEAP here so it can be used by all files
#define MAX_HEAP 6000

// STRUCT: This defines the structure used for both file cleaning and the heap.
typedef struct {
    char event_id[32];
    int key1;
    int key2;
} HeapNode;

// Globals from heap.c 
extern HeapNode heap[MAX_HEAP];
extern int heap_size;

// Function Declarations
void log_heap_state(const char *operation);
int is_smaller(HeapNode nodeA, HeapNode nodeB);
void insert(HeapNode *A, HeapNode x);
HeapNode extract_min(HeapNode *A);
void decrease_key(HeapNode *A, char event_id[], int newK1, int newK2);
void print_heap_array(HeapNode *A, FILE *fp);
void build_heap(FILE *fp);

#endif