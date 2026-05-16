# include <stdio.h>
# include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode (int val){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

// With return type
Node* insertBeginning (Node* head, int val){
    // create node with val
    Node* newNode = createNode(val);

    newNode->next = head;
    head = newNode;

    return head;
}

// Without return type
void insert_Beginning (Node** head, int val){
    Node* newNode = createNode(val);
    
    newNode->next = *head;
    *head = newNode;
}

Node* insertEnd (Node* head, int val){
    // create newNode
    Node* newNode = createNode(val);

    // check if it is an empty list
    // we do not want to traverse an empty list

    if (head == NULL){
        head = newNode;
    } else {
        Node* temp = head;
        // traverse to the last node
        // the node before temp is null
        while (temp->next != NULL){
            temp = temp->next;
        }
        // set the last node next to newnode
        temp->next = newNode;
    }

    return head;
}

// with void

void insert_End (Node** head, int val){
    Node* newNode = createNode(val);

    if (*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;

        while (temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Inserting at a given position

Node* insertAt (Node* head, int pos, int val){
    if (pos < 0) {
        fprintf(stderr, "Invalid position\n");
        return head;
    }

    Node* newNode = createNode(val);

    if (pos == 0){
        newNode->next = head;
        return newNode; // Now the head of the list
    }

    // Now traverse to the pos
    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL){
        fprintf(stderr, "Invalid position\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// reverse a linked list

Node* reverse (Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    Node* head = NULL;

    // Using return-type insertion
    head = insertBeginning(head, 10);
    head = insertEnd(head, 20);
    head = insertAt(head, 1, 15);   
    printList(head); 

    // Using void-type insertion
    insert_Beginning(&head, 5);
    insert_End(&head, 25);
    printList(head); 

    // Invalid insert
    head = insertAt(head, 10, 99); 
    printList(head); // List unchanged

    // Reverse

    head = reverse(head);
    printList(head);

    freeList(head);
    free(head);
    
    return 0;
}