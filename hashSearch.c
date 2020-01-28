#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
void print(struct Node * p);
struct Node * insert_link_list(struct Node * linke_list,int number);
void hash_add(int number , struct Node * array[]);
int hash_search(int number , struct Node * array[]);
void hash_delete(int number , struct Node * array[]);
void hash_print(struct Node * array[]);
int main(){
    struct Node * array[10] = {NULL};
    hash_add(1,array);
    hash_add(19,array);
    hash_add(4,array);
    hash_add(65,array);
    hash_add(99,array);
    int c = hash_search(19,array);
    hash_delete(19,array);
    hash_print(array);
    printf("\n%d",c);
	return 0;
}
void hash_add(int number , struct Node * array[]){
    int index = number % 10 ;
    array[index] = insert_link_list(array[index],number);
}
struct Node * insert_link_list(struct Node * linke_list,int number){
    struct Node * temp = linke_list;
    if (linke_list == NULL){
        struct Node *linke2_list = (struct Node *)malloc(sizeof(struct Node*));
        linke2_list -> next = NULL;
        linke2_list -> data = number;
        return linke2_list;
    }
    else {
        while (linke_list -> next != NULL)
                linke_list = linke_list -> next;
        linke_list-> next = (struct Node *)malloc(sizeof(struct Node*));
        linke_list ->next -> next = NULL;
        linke_list -> next -> data = number;
    }
    return temp;
}
int hash_search(int number , struct Node * array[]){
    int index = number % 10 ;
    struct Node* temp = array[index];
    while (temp != NULL){
        if (temp -> data == number)
            return 1 ;
        else
            temp = temp -> next;
    }
    return 0 ;
}
void hash_print(struct Node *array[]){
    int i ;
    for (i = 0 ; i < 10 ; i++){
        print(array[i]);
        printf("\n");
    }
}
void print(struct Node * p){
    while (p != NULL){
        printf("%d ",p->data);
        p = p -> next ;
    }
}
void hash_delete(int number , struct Node * array[]){

    int index = number % 10 ;
    struct Node *temp = array[index];
    if (temp == NULL)
        return ;
    while (temp -> next != NULL){
        if (temp -> next -> data == number){
                temp -> next = temp -> next -> next ;

        }
        temp = temp -> next ;
    }
    array[index] = temp ;
}
