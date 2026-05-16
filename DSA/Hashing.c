#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

HashTable* initTable() {
    HashTable* ht = malloc(sizeof(HashTable));
    if (!ht) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

Node* createNode(int key) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTable* ht, int key) {
    int index = hash(key);
    Node* newNode = createNode(key);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int search(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];

    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void delete(HashTable* ht, int key) {
    int index = hash(key);
    Node* current = ht->table[index];
    Node* prev = NULL;


    while (current != NULL) {
        if (current->data == key) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Deleted %d\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key %d not found\n", key);
}

void printTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* current = ht->table[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

// 🌟 MAIN FUNCTION TO TEST EVERYTHING
int main() {
    HashTable* ht = initTable();

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);
    insert(ht, 5);
    insert(ht, 15);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 4);
    insert(ht, 12);
    insert(ht, 11);
    insert(ht, 13);

    printf("\nHash Table:\n");
    printTable(ht);

    printf("\nSearching for 20: %s\n", search(ht, 20) ? "Found" : "Not Found");
    printf("Searching for 99: %s\n", search(ht, 99) ? "Found" : "Not Found");

    delete(ht, 20);
    delete(ht, 99);

    printf("\nHash Table After Deletions:\n");
    printTable(ht);

    freeTable(ht);
    return 0;
}
