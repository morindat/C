# include <stdio.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

Node* createNode(int data);
Node* insertBeginning(Node* head, int data);
Node* insertEnd(Node* head, int data);
Node* insertAtpos(Node* head, int pos, int data);
Node* deleteBeginning(Node* head);
Node* deleteEnd(Node* head);
Node* deleteAt(Node* head, int pos);
Node* print(Node* head);
int search(Node* head, int value);
Node* reverse(Node* head);

Node *createNode(int data){
    Node *newNode = malloc (sizeof(Node));
    
    if(!newNode){
        fprintf(stderr, "Memory allocation failed!");
        exit(EXIT_FAILURE);
        // return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Node *insertBeginning (Node *head, int data){
    Node *newNode = createNode(data);
    newNode->next = head;

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

    return head;
}

Node *insertAtpos(Node *head, int pos, int data){
    Node *newNode = createNode(data);

    if (pos == 0){
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL){
        printf("Out of bounds!");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;

}

Node *deleteBeginning(Node *head){
    if (head == NULL){
        printf("Nothing to free");
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node *deleteEnd(Node *head){
    if (head == NULL){
        printf("Nothing to free");
        return NULL;
    }

    if  (head->next == NULL){
        free(head);
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

Node *deleteAt(Node *head, int pos){
    if (head == NULL) return NULL;

    if (pos == 0){
        return deleteBeginning(head);
    }

    Node *temp = head;
    int i = 0;
    
    while (i < pos -1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return head;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;

}

Node *print (Node *head){
    if (head == NULL){
        printf("Empty List\n");
        return NULL;
    }

    Node *temp = head;
    
    printf("Linked List: ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

}

int search(Node *head, int value){
    if (head == NULL){
        printf("List is empty\n");
        return -1;
    }

    Node *temp = head;

    int i = 0;
    while (temp != NULL){
        if (temp->data == value){
            return i;
        }
        temp = temp->next;
        i++;
    }

    return -1;
}

Node *reverse (Node *head){
    Node *Curr = head;
    Node *Next = NULL;
    Node *Prev = NULL;

    while (Curr != NULL){
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }

    return Prev;
}

int main(){
    Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    head = reverse(head);
    head = insertBeginning(head, 0);
    head = deleteBeginning(head);
    head = deleteAt(head, 2);
    head = deleteBeginning(head);
    head = insertAtpos(head, 1, 30);


    print(head);
}