# include <stdlib.h>
# include <stdio.h>

# define TABLE_SIZE 10

typedef struct Node{
    int key;
    char value;
    struct Node *next;
} Node;

typedef struct HT{
    Node *table[TABLE_SIZE];
} HT;

HT *initTable(){
    HT *ht = malloc (sizeof(HT));
    if(!ht){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABLE_SIZE; i++){
        ht->table[i] = NULL;
    }

    return ht;
}

Node *createNode(int data, char val){
    Node *newnode = malloc(sizeof(Node));

    if (!newnode){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newnode->key = data;
    newnode->value = val;
    newnode->next = NULL;

    return newnode;
}

int hash(int key){
    return key % TABLE_SIZE;
}

int hashFreq(char key) {
    return (key - 'a') % TABLE_SIZE;
}

void insert(HT *ht, int key, char val){
    int ind = hash(key);
    Node *current = ht->table[ind];

    while (current != NULL){
        if (current->key == key){
            current->value = val;
            return;
        }
        current = current->next;
    }

    Node *newnode = createNode(key, val);
    newnode->next = ht->table[ind];
    ht->table[ind] = newnode;
}

void insertFreq(HT* ht, char key) {
    int index = hash(key);
    Node* current = ht->table[index];

    // Look for existing key
    while (current) {
        if (current->key == key) {
            current->value++; // update frequency
            return;
        }
        current = current->next;
    }

    // Not found → create new node and insert at head
    Node* newNode = createNode(key, 1);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int search(HT *ht, int key, char* out){
    int ind = hash(key);
    Node *curr = ht->table[ind];

    while (curr != NULL){
        if (curr->key == key){
            *out = curr->value;
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

void delete(HT *ht, int key){
    int ind = hash(key);
    Node *curr = ht->table[ind];
    Node *prev = NULL;

    while(curr != NULL){
        if (curr->key == key){
            if(prev == NULL){
                ht->table[ind] = curr->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            printf("Deleted key %d\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Key %d not found!\n", key);
}

void print(HT* ht){
    if (!ht) return;

    for(int i = 0; i < TABLE_SIZE; i++){
        printf("[%d]: ", i);

        Node *curr = ht->table[i];
        while (curr != NULL){
            printf("(%d, '%c') -> ", curr->key, curr->value);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

void printFrequencies(HT* ht) {
    printf("Character Frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        while (current) {
            printf("%c: %d\n", current->key, current->value);
            current = current->next;
        }
    }
}

// Free the table
void freeTable(HT* ht) {
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


int main() {
    HT* ht = initTable();
    HT *table =initTable();
    char *str ="abracadabra";

    for (int i = 0; str[i] != '\0'; i++){
        insertFreq(table, str[i]);
    }

    printFrequencies(table);
    freeTable(table);

    insert(ht, 65, 'A');
    insert(ht, 66, 'B');
    insert(ht, 75, 'K');  
    insert(ht, 65, 'Z');  

    print(ht);

    char value;
    if (search(ht, 66, &value))
        printf("Found key 66 with value: %c\n", value);
    else
        printf("Key 66 not found\n");

    delete(ht, 75);
    print(ht);

    return 0;
}