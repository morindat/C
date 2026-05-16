#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Huffman Tree node
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

// Min-Heap for nodes
typedef struct MinHeap {
    int size;
    int capacity;
    Node **array;
} MinHeap;

// Create a new node
Node* createNode(char ch, int freq) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Create min heap of given capacity
MinHeap* createMinHeap(int capacity) {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node**)malloc(capacity * sizeof(Node*));
    return heap;
}

// Swap two nodes
void swapNode(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify at given index
void minHeapify(MinHeap *heap, int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Extract min node
Node* extractMin(MinHeap *heap) {
    Node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return temp;
}

// Insert a node into min heap
void insertMinHeap(MinHeap *heap, Node *node) {
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = node;

    while (i && heap->array[i]->freq < heap->array[(i-1)/2]->freq) {
        swapNode(&heap->array[i], &heap->array[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Build min heap
void buildMinHeap(MinHeap *heap) {
    int n = heap->size;
    for (int i = (n-1)/2; i >=0; i--)
        minHeapify(heap, i);
}

// Check if node is leaf
int isLeaf(Node *node) {
    return !(node->left) && !(node->right);
}

// Build Huffman tree from frequencies
Node* buildHuffmanTree(int freq[]) {
    MinHeap *heap = createMinHeap(MAX_CHAR);

    // Create leaf nodes for characters with freq > 0
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            heap->array[heap->size++] = createNode((char)i, freq[i]);
        }
    }

    buildMinHeap(heap);

    while (heap->size > 1) {
        Node *left = extractMin(heap);
        Node *right = extractMin(heap);

        Node *top = createNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    Node *root = extractMin(heap);
    free(heap->array);
    free(heap);
    return root;
}

// Print Huffman codes recursively
void printCodes(Node *root, char code[], int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top+1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top+1);
    }
    if (isLeaf(root)) {
        code[top] = '\0';
        printf("%c: %s\n", root->ch, code);
    }
}

// Build frequency map from string
void buildFreqMapFromString(const char *str, int freq[]) {
    for (int i = 0; i < MAX_CHAR; i++) freq[i] = 0;
    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;
}

int main() {
    const char *text = "this is an example for huffman encoding";
    int freq[MAX_CHAR];

    buildFreqMapFromString(text, freq);

    Node *root = buildHuffmanTree(freq);

    char code[MAX_CHAR];
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}
