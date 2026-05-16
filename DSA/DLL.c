# include <stdlib.h>
# include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode (int val){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode){
        fprintf (stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

// Inserting at beginning

Node* insertBeginning (Node* head, int val){
    // Create new node
    Node* newNode = createNode(val);
    newNode->next = head;
    
    if (head != NULL){
        head->prev = newNode;
    }

    return newNode; // You could also make head = newNode and return head
}

// Inserting at the end
Node* insertEnd (Node* head, int val){
    // As always create the newnode to store val and nec pointers
    Node* newNode = createNode(val);

    if (head == NULL){
        return newNode; // now this is the head, its next and prev are both null for now
    }

    // if there is elements, traverse the list to element at the end/ last node
    Node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    // set temp next to newnode and newnode prev to temp
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// insert at a position
Node* insertAt (Node* head, int pos, int val){
    Node* newNode = createNode(val);

    if (pos == 0){
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    // If temp is null then we are out of bounds before we even reach the pos so free newnode and return head
    if (temp == NULL){
        fprintf(stderr, "Index out of bounds\n");
        free(newNode);
        return(head);
    }

    // If temp next is not null, we have not reached the end of the list
    // temp next is newnode (forward)
    // newNode next is the temp next  (forward)
    // temp next prev is newnode (backward)
    // newnode prev is temp (backward)
    // we can return the head here 
    // i guess this connects all nodes

    if (temp->next != NULL){
        temp->next->prev = newNode;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;

        return head;
    }

    // but if it at the end of the list
    // then temp next is newnode and connect that to the temp by newnode prev
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}


// Deleting
Node* deleteBeginnig (Node* head){
    if (head == NULL){
        fprintf(stderr, "Nothing to delete\n");
        exit(EXIT_FAILURE);
    };

    Node* temp = head;
    head = head->next;

    if (head != NULL){
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Delete end node
// First thing tomorrow when i wake up

Node* deleteEnd (Node* head){
    if (head == NULL){
        return NULL;
    } else if (head->next == NULL){
        free(head);
        return NULL;
    } else {
        // If this is wrong then i guess i am missing the connection between NULL and the last node
        Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        } 
        temp->prev->next = NULL;
        free(temp);
    }

    return head;
}

// Delete at

Node* deleteAt(Node* head, int pos) {
    if (head == NULL) {
        fprintf(stderr, "List is empty\n");
        return NULL;
    }

    // Case 1: delete head
    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    // Traverse to node at position pos
    Node* temp = head;
    int i = 0;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    // Out of bounds
    if (temp == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        return head;
    }

    // Unlink temp
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}


// Print list forward
void printList(Node* head) {
    Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        if (temp->next == NULL) break; // remember the last for backward print
        temp = temp->next;
    }
    printf("NULL\n");

    // Print backwards from the last node
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Free entire list
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

    // Insert at end
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);

    // Insert at beginning
    head = insertBeginning(head, 5);
    printList(head);

    // Insert at position
    head = insertAt(head, 2, 15); // insert 15 at pos 2
    printList(head);

    // Delete at beginning
    head = deleteBeginnig(head);
    printList(head);

    // Delete at end
    head = deleteEnd(head);
    printList(head);

    // Delete at position
    head = deleteAt(head, 1); // delete node at pos 1
    printList(head);

    // Free memory
    freeList(head);
    return 0;
}
