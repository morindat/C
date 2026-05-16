# include <stdlib.h>
# include <stdio.h>


typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode (int val) {
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void printHead (Node* head){
    Node* temp = head;

    while (temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeNodes(Node* head){
    if (head == NULL){
        return;
    }

    Node* temp = head;
    while(temp){
        Node* curr = temp;
        temp = temp->next;
        free(curr);
    }

    head = NULL;
}

Node* insertBeginning (Node* head, int val){
    Node* newNode = createNode(val);
    
    newNode->next = head;
    head = newNode;

    return head;
}

Node* insertEnd (Node* head, int val){
    Node* newNode = createNode(val);

    // if the head is null, insert beggining
    // else traverse to the end

    if (head == NULL){
        head = newNode;
        return head;
    }

    Node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

Node* insertAt (Node* head, int val, int pos){
    Node* newNode = createNode(val);

    // inserting at the beginning
    if (pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    // anywhere else
    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        i++;
        temp = temp->next;
    }

    if (temp == NULL){
        fprintf(stderr, "Index out of bounds");
        free(newNode);
        return head;
    }

    // If the pos is the last node, point the last node to newnode only and return head
    if (temp->next == NULL){
        temp->next = newNode;
        return head;
    }

    // Otherwise, somewhere in the middle
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* deleteBeginning (Node* head){

    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node* deleteEnd(Node* head){
    if (head == NULL){
        return NULL;
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;

    while (temp->next->next != NULL){
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = NULL;
    free(toDelete);

    return head;
}

Node* deleteAt(Node* head, int pos){

    if (head == NULL){
        fprintf(stderr, "List is empty\n");
        exit(EXIT_FAILURE);
    }

    // The first node
    if (pos == 0){
        Node*temp = head;
        head = head->next;
        free(temp);
        return head;
    }


    // Many nodes present
    
    int i = 0;
    Node* temp = head;
    
    while (i < pos - 1 && temp != NULL){
        i++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL){
        fprintf(stderr, "Invalid index\n");
        exit(EXIT_FAILURE);
    }

    Node* toDel = temp->next;
    temp->next = toDel->next;
    free(toDel);

    return head;

}

Node* reverse (Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


int main(){
    Node* head = NULL;

    head = insertBeginning(head, 10);
    head = insertEnd(head, 30);
    head = insertAt(head, 20, 1);
    printHead(head);
    head = reverse(head);
    printHead(head);
    head = deleteAt(head, 1);
    printHead(head);


    freeNodes(head);
    return 0;
}