# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

Node* insert (Node* head, int val){
    Node* newNode = createNode(val);

    if (head == NULL){
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;    
    }

    return head;
}

void printList (Node* head){
    if (head == NULL){
        fprintf(stderr, "Nothing to print\n");
        return;
    }

    Node* temp = head;

    while (temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void freeNodes (Node* head){
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

Node* deleteNodes (Node* head, int val){
    // we need to delete all nodes with value val
    // while temp is not null
    // delete and connect the list

    Node* prev = NULL;
    Node* temp = head;

    while (temp){
        if (temp->data == val){
            Node* curr = temp;
            if (prev == NULL){
                // Meaning the first occurence of val is the head
                // we need to move the head to next 
                head = temp->next;
            } else {
                // occurence of val is anywhere else in the head
                prev->next = temp->next;
            }
            // move temp on and free curr/delete it
            temp = temp->next;
            free(curr);
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

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

Node* buildNodes (int num){
    Node* head = NULL;

    while (num){
        int numExtract = num % 10;
        num = num / 10;
        head = insert(head, numExtract);
    }

    head = reverse(head);
    return head;
}

Node* addNodes (Node* head1, Node* head2){
    Node* head = NULL;

    int len = 0, len2 = 0;

    Node* temp = head1;
    while (temp){
        len++;
        temp = temp->next;
    }

    Node* temp2 = head2;
    while (temp2){
        len2++;
        temp2 = temp2->next;
    }

    char* str = malloc((len + 1) * sizeof(char));
    if (!str) return NULL;

    char* str2 = malloc((len2 + 1) * sizeof(char));
    if (!str2) {
        free(str);
        return NULL;
    }

    temp = head1;
    for (int i = 0; i < len; i++){
        str[i] = temp->data + '0';
        temp = temp->next;
    }
    str[len] = '\0';

    temp2 = head2;
    for (int i = 0; i < len2; i++){
        str2[i] = temp2->data + '0';
        temp2 = temp2->next;
    }
    str2[len2] = '\0';

    int sum = atoi(str) + atoi(str2);

    free(str);
    free(str2);

    head = buildNodes(sum);
    
    return head;
}


int main(){
    Node* head = NULL;
    Node* head2 = NULL;

    head = insert(head, 9);
    head = insert(head, 7);
    head = insert(head, 1);
    head = insert(head, 7);

    head2 = insert(head2, 6);
    head2 = insert(head2, 4);
    head2 = insert(head2, 3);

    Node* sumList = addNodes(head, head2);
    printf("Sum list: ");
    printList(sumList);


    printList(head);
    printList(head2);

    head = reverse(head);
    printList(head);

    head = deleteNodes(head, 7);
    printf("List after deleting repeating nodes: ");
    printList(head);

    Node* list = buildNodes(11029);
    printList(list);


    freeNodes(head);
    freeNodes(head2);
    freeNodes(list);
    freeNodes(sumList);

    return 0;
}
