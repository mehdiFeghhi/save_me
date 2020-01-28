# include <stdio.h>
# include <stdlib.h>
struct Node {
    int data ;
    struct node* next;
    struct node* before;

};
struct Node* add_first(int number , struct Node *head){
    struct Node* new_val ;
    new_val  = (struct Node *)malloc(sizeof(struct Node));
    if (head != NULL)
        head -> before = new_val;
     new_val -> next = head;
     new_val -> before = NULL;
     new_val -> data = number;
     return new_val;
}
struct Node* add_last(int number , struct Node *head){
    struct Node* new_val ;
    new_val = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head ;
    if (head == NULL){
        head = new_val;
        new_val -> next = NULL;
        new_val -> before = NULL;
        new_val -> data = number;
        return new_val;
    }
    else {
    while (temp -> next != NULL)
        temp = temp -> next ;
    temp -> next = new_val ;
    new_val -> before = temp ;
    new_val -> next = NULL;
    new_val -> data = number;
    return head ;
    }
}
struct Node *insert(int number , int index , struct Node *head){
    int counter ;
    struct Node * temp = head ;
    struct Node * temp2;
    struct Node * new_val;
    new_val = (struct Node *)malloc(sizeof(struct Node));
    for (counter = 0 ; counter < index ; counter++)
        temp = temp -> next ;
    temp2 = temp -> next ;
    temp -> next = new_val;
    new_val -> before = temp ;
    new_val -> next = temp2;
    temp2 -> before = new_val;
    return head;
}
