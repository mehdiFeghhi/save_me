#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




struct b_tree{
    int low;
    int high;
    int how_much_number;
    struct b_tree *little_child;
    struct b_tree *middle_child;
    struct b_tree *high_child;

};
void full_array(struct b_tree *head,int *i,int array[]);
struct b_tree *ballance(struct b_tree *head);
struct b_tree *insert_b_tree(struct b_tree *head,int number);
struct b_tree *make_ballance(struct b_tree *head,int array[],int high);
struct b_tree *a_free(struct b_tree *head);
void print(struct b_tree *head);

int main(){
    struct b_tree *first = NULL;
    first = insert_b_tree(first,6);
    first = insert_b_tree(first,1);
    first = insert_b_tree(first,5);
    first = insert_b_tree(first,3);
    first = insert_b_tree(first,9);
    first = insert_b_tree(first,12);
    first = insert_b_tree(first,7);
    first = insert_b_tree(first,21);
    first = insert_b_tree(first,14);
    first = insert_b_tree(first,16);
    first = insert_b_tree(first,2);
    //print(first);
    first = ballance(first);
    //int i ,j= 0;
    //int array[1000];
    //full_array(first,&i,array);
    //for (j = 0 ;j<i;j++)
       // printf("%d ",array[j]);
   print(first);
   return 0;
}
struct b_tree *insert_b_tree(struct b_tree *head , int number){
    struct b_tree *temp = head ;
    if (head == NULL){
        struct b_tree *new_val = (struct b_tree *)malloc(sizeof(struct b_tree));
        new_val ->little_child = NULL;
        new_val ->middle_child = NULL;
        new_val ->high_child = NULL;
        new_val ->how_much_number = 1;
        new_val ->low = number;
        return new_val;
    }
    else if (temp ->how_much_number == 1){
        if (temp ->low > number){
            temp ->high = temp ->low;
            temp ->low = number ;
            temp ->how_much_number = 2;
            return head;
        }
        temp ->how_much_number = 2 ;
        temp -> high = number;
        return head;
    }
    else if (temp ->how_much_number == 2){

        if (temp -> low > number)
            temp ->little_child = insert_b_tree(temp->little_child , number);
        else if (temp -> low < number && temp->high > number)
            temp -> middle_child = insert_b_tree(temp->middle_child,number);
        else if (temp -> high < number)
            temp -> high_child = insert_b_tree(temp ->high_child,number);
        return head;
    }
}
void print(struct b_tree *head){
    struct b_tree*temp = head;
    if (temp == NULL)
        return;
    if (head->how_much_number == 2){
        print(temp ->little_child);
        printf("\n%d",head->low);
        print(temp ->middle_child);
        printf("\n%d",head->high);
        print(temp ->high_child);
        }
    else if (head->how_much_number == 1){
        printf("\n%d",head->low);

    }
}
void afree(struct b_tree *head){

    afree(head->little_child);
    afree(head->middle_child);
    afree(head->high_child);
    free(head);
}
struct b_tree *ballance(struct b_tree *head){
    struct b_tree *new_val = NULL;
    int array[1000];
    int i = 0;
    full_array(head ,&i,array);
    new_val = make_ballance(new_val,array,i);
    return new_val;
}
struct b_tree *make_ballance(struct b_tree *head,int array[],int i){
       if (i == 1){
            head = insert_b_tree(head,array[0]);
            return head ;
       }
       else if (i == 2){
            head = insert_b_tree(head,array[0]);
            head = insert_b_tree(head,array[1]);
            return head;
       }
       else if(i == 3){
            head = insert_b_tree(head,array[0]);
            head = insert_b_tree(head,array[2]);
            head = insert_b_tree(head ,array[1]);
            return head;
       }
       else if (i == 4){
            head = insert_b_tree(head,array[0]);
            head = insert_b_tree(head,array[3]);
            head = insert_b_tree(head ,array[1]);
            head = insert_b_tree(head,array[2]);
            return head;
       }
       else if (i == 5){
            head = insert_b_tree(head,array[1]);
            head = insert_b_tree(head,array[3]);
            head = insert_b_tree(head,array[0]);
            head = insert_b_tree(head,array[4]);
            head = insert_b_tree(head,array[2]);
            return head;
       }
       else {
            int array1[(i/3)+3];
            int array2[(i/3)+3];
            int array3[(i/3)+3];
            int j ,c;
            c = 0 ;
            head = insert_b_tree(head ,array[i/3]);
            head = insert_b_tree(head , array[(i*2)/3]);
            for (j = 0 ;j < i/3 ; j++){
                array1[c]= array[j];
                c++;
            }
            head = make_ballance(head,array1,c-1);
            c = 0;
            for (j = (i /3) +1; j < (i*2)/3 ;j++){
                array2[c] = array[j];
                c++;
            }
            head = make_ballance(head,array2,c-1);
            c = 0 ;
            for (j = (i*2)/3 + 1 ; j < i ; j++){
                array3[c] = array[j];
                c++;
            }
            head = make_ballance(head,array3,c-1);
            return head;
       }
}
void full_array(struct b_tree *h,int *i,int array[]){
        struct b_tree *head = h;
        if (head == NULL)
            return ;
        if (head ->how_much_number == 2){
            full_array(head ->little_child ,i,array);
            array[*i]= head ->low;
            *i = *i + 1;
            full_array(head ->middle_child,i,array);
            array[*i] = head ->high;
            *i = *i + 1;
            full_array(head->high_child,i,array);
        }
        else if  (head ->how_much_number == 1){
            array[*i]=head ->low;
            *i = *i + 1;
            return ;
        }
}
