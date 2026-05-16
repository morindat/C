# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

#define T_SIZE 11
#define deleted_key -1

typedef struct Entry {
    int key;
    char value;
    bool is_occupied;
    bool is_deleted;
} Entry;

typedef struct HashTable {
    Entry table[T_SIZE];
} HashTable;

int hash(int key){
    return key % T_SIZE;
}

void initTable(HashTable *ht){
    for (int i = 0; i < T_SIZE; i++){
        ht->table[i].is_deleted = false;
        ht->table[i].is_occupied = false;
    }
}

// gave up half way coz insertion is way too complicated, not worthy the effort
// plus the array isn't even dynamic, tf is it
