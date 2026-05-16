# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode (int val){
    Node* newNode = (Node*) malloc (sizeof(Node));
    if (!newNode){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void printHead (Node* head){
    if (head == NULL){
        fprintf(stderr, "Nothing to print\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = head;
    while (temp){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
} 

void freeNodes(Node* head){
    if (head == NULL){
        return;
    }

    Node* temp = head;

    while (temp){
        Node* curr = temp;
        temp = temp->next;
        free(curr);
    }

    head = NULL;
}

Node* insertBeginning(Node* head, int val){
    Node* newNode = createNode(val);

    newNode->next = head;

    if (head != NULL){
        head->prev = newNode;
    }

    return newNode;
   
}

Node* insertEnd(Node* head, int val){
    Node* newNode = createNode(val);
    
    if (head == NULL){
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;

}

Node* insertAt(Node* head, int pos, int val){
    Node* newNode = createNode(val);

    if (pos == 0){
        newNode->next = head;
        if (head != NULL){
            head->prev = newNode;
        }
        return newNode;
    }

    int i = 0;
    Node* temp = head;

    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL){
        fprintf(stderr, "Index out of bounds\n");
        free(newNode);
        return(head);
    }

    if (temp->next != NULL){
        temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        return head;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;

}

Node* deleteBeginning (Node* head){
    if (head == NULL){
        fprintf(stderr, "Nothing to delete here\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL){
        head->prev = NULL;
    }
    free(temp);
    return head;
}

Node* deleteEnd(Node* head){
    if (head == NULL){
        fprintf(stderr, "Nothing to delete here\n");
        exit(EXIT_FAILURE);
    }

    if (head->next == NULL){
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    Node* toDelete = temp;
    temp->prev->next = NULL;

    free(toDelete);
    return head;
}

Node* deleteAt(Node* head, int pos){
    if (head == NULL){
        fprintf(stderr, "Nothing to delete here\n");
        exit(EXIT_FAILURE);
    }

    if (pos == 0){
        Node* temp = head;
        head = head->next;

        if (head != NULL){
            head->prev = NULL;
        }
        free(temp);

        return head;
    }

    Node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != NULL){
        i++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL){
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    Node* toDel = temp->next;
    temp->next = toDel->next;
    if (toDel->next != NULL){
        toDel->next->prev = temp;
    }

    free(toDel);
    return head;
}

Node* search(Node* head, int key){
    if (head == NULL){
        fprintf(stderr, "Empty list\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = head;
    while (temp){
        if (temp->data == key){
            printf("Found: %d\n", key);
            return temp;
        }
        temp = temp->next;
    }
    printf ("%d: Not found!\n", key);
    return NULL;
}

int main() {
    Node* head = NULL;

    printf("=== INSERT TESTS ===\n");
    head = insertBeginning(head, 10); 
    head = insertBeginning(head, 5); 
    head = insertEnd(head, 20);    
    head = insertEnd(head, 25);        
    head = insertAt(head, 2, 15);       
    printHead(head);

    printf("\n=== DELETE TESTS ===\n");
    head = deleteBeginning(head);    
    printHead(head);

    head = deleteEnd(head);             
    printHead(head);

    head = deleteAt(head, 1);          
    printHead(head);

    head = deleteAt(head, 1);           
    printHead(head);

    head = deleteAt(head, 0);           
    printHead(head); 

    freeNodes(head);
    return 0;
}
