# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data){
    Node *newNode = malloc(sizeof(Node));
    
    if(!newNode){
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

Node *insertBeginning(Node *head, int data){
    Node *newNode = createNode(data);

    if (head == NULL){
        return newNode;
    }

    newNode->next = head;
    newNode->prev = NULL;
    head->prev = newNode;

    return newNode;
}

Node *insertEnd(Node *head, int data){
    Node *newNode = createNode(data);

    if (head == NULL){
        return newNode;
    }

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;

    return head;
}

Node *insertAt(Node *head, int pos, int data){
    Node *newNode = createNode(data);

    if (head == NULL || pos == 0){
        newNode->next = head;
        if (head != NULL){
            head->prev = newNode;
        }
        return newNode;
    }

    Node *temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;


    if (temp->next != NULL){
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;

    return head;
}

Node *deleteBeginning(Node *head){
    if(head == NULL) return NULL;

    Node *temp = head;
    head = head->next;

    if (head != NULL){
        head->prev = NULL;
    }

    free(temp);

    return head;
}

Node *deleteEnd(Node *head){
    if (head == NULL){
        printf ("List is empty");
        return NULL;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);

    return head;
}

Node *deleteAt (Node *head, int pos){
    if (head == NULL) return NULL;

    Node *temp = head;

    if (pos == 0){
        head = head->next;
        if (head != NULL){
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    int i = 0;
    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL){
        printf("Invalid Index\n");
        return head;
    }

    if (temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    free(temp);

    return head;
}

void print(Node* head){
    if (head == NULL){
        printf("Forward: (empty)\n");
        return;
    }

    Node *temp = head;
    printf("Forward: ");
    while (temp != NULL){
        printf ("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(Node* head) {
    if (head == NULL) {
        printf("Backward: (empty)\n");
        return;
    }

    
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");

}

int main() {
    Node *head = NULL;

    // Insert at beginning
    head = insertBeginning(head, 10); // 10
    head = insertBeginning(head, 5);  // 5 10
    print(head);
    printBackward(head);

    // Insert at end
    head = insertEnd(head, 20);       // 5 10 20
    head = insertEnd(head, 25);       // 5 10 20 25
    print(head);
    printBackward(head);

    // Insert at position
    head = insertAt(head, 2, 15);     // 5 10 15 20 25
    head = insertAt(head, 0, 1);      // 1 5 10 15 20 25
    print(head);
    printBackward(head);

    // Delete beginning
    head = deleteBeginning(head);     // 5 10 15 20 25
    print(head);
    printBackward(head);

    // Delete end
    head = deleteEnd(head);           // 5 10 15 20
    print(head);
    printBackward(head);

    // Delete at position
    head = deleteAt(head, 1);         // 5 15 20
    print(head);
    printBackward(head);

    return 0;
}