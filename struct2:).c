#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stu{
    int student_number;
    float average ;
    float all ;
    int number_point;
    struct stu *next ;
    struct po *top;
};
struct po{
    float point ;
    struct po *next ;
};
struct stu* search(struct stu *head , int number);
struct stu* insert(struct stu *head , int number);
struct stu* add_point(struct stu *head,int number,float point);
struct stu* calculate(struct stu *head);
struct stu *sort_a(struct stu *head);
struct po* insert_point(struct po *head , float point);
void print(struct stu *head);
int main(){
    int c , is_end,have_student_number,student_number,i;
    float point;
    char *p = (char *)malloc(sizeof(char)*1000);
    struct stu *first = NULL;
    is_end = have_student_number = i = 0 ;
    FILE *fp;
    fp = fopen("grades.txt","r");
    if (fp == NULL)
        return 1;
    while ((c = getc(fp))!= EOF){
        if(isdigit(c) && have_student_number == 0){
            *(p+i)= c ;
            i++;
        }
        else if (c == ' ' && have_student_number == 0){
            *(p+i)= '\0';
            have_student_number = 1;
            student_number = atoi(p);
            first = insert(first,student_number);
            i = 0 ;
        }
        else if ( (isdigit(c)|| c == '.') && have_student_number == 1){
            *(p+i)= c ;
            i++;
        }
        else if (c ==' '&& have_student_number == 1){
            *(p+i) = '\0';
            point  = atof(p);
            first = add_point(first,student_number,point);
            i = 0;
        }
        else if (c == '\n'){
            have_student_number = 0 ;
            *(p+i) = '\0';
            point = atof(p);
            first = add_point(first,student_number,point);
            i = 0 ;
        }
        else
            return 1;
    }
    first = calculate(first);
    first = sort_a(first);
    print(first);
    return 0 ;
}
struct stu* insert(struct stu *head,int number){
    struct stu *temp = head ;
    struct stu *new_val = (struct stu *)malloc(sizeof(struct stu));
    new_val ->next = NULL;
    new_val ->top = NULL;
    new_val ->number_point = 0;
    new_val ->all = 0 ;
    new_val ->average = 0;
    new_val ->student_number = number;
    if (head == NULL)
        return new_val;
    else{
        while (temp->next != NULL)
            temp = temp->next;

        temp -> next = new_val;
        return head ;
    }
}
struct stu* add_point(struct stu *head , int student_number ,float point){
    struct stu *temp = head ;
    struct stu *temp2  = search(temp,student_number);
    if (temp2 == NULL)
        return head;
    temp2 ->number_point++;
    temp2 ->all += point ;
    temp2 -> top = insert_point(temp2->top,point);
    return head ;
}
struct po* insert_point(struct po *head , float point){
    struct po *temp = head ;
    struct po *new_val = (struct po *)malloc(sizeof(struct po));
    new_val ->next = NULL;
    new_val ->point = point;
    if (head == NULL)
        return new_val;
    else{
        while (temp->next != NULL)
            temp = temp->next;

        temp -> next = new_val;
        return head;
    }
}
struct stu* search(struct stu* head ,int number){
    struct stu* temp = head ;
    while  (temp != NULL){
        if (temp -> student_number != number)
            temp = temp -> next ;
        else
            return temp;
    }
    return temp;
}
struct stu* calculate(struct stu *head){

    struct stu* temp = head ;
    while (temp !=NULL){
        temp->average = temp->all / temp->number_point;
        temp = temp -> next;
    }
    return head ;
}
struct stu *sort_a(struct stu *head){
    int exch_student_number;
    float exch_ave ;
    float exch_all ;
    int exch_number_point;
    struct po *exch_top = NULL;
    int change = 1 ;
    struct stu *temp = head ;
    if (temp == NULL)
        return head;
    else {
        while (change != 0){
            change = 0 ;
            while (temp -> next != NULL){
                  if (temp -> average < temp ->next -> average){
                     exch_student_number = temp ->next->student_number;
                     exch_ave = temp ->next->average;
                     exch_all = temp ->next->all;
                     exch_number_point = temp ->next ->number_point;
                     exch_top = temp ->next->top;
                     temp ->next->student_number = temp->student_number;
                     temp ->next->average = temp -> average;
                     temp ->next->all = temp -> all;
                     temp ->next ->number_point = temp -> number_point;
                     temp ->next->top = temp ->top;
                     temp ->student_number =exch_student_number ;
                     temp ->average = exch_ave;
                     temp ->all =exch_all ;
                     temp ->number_point = exch_number_point ;
                     temp ->top = exch_top;
                     change = 1;
                  }
                    temp = temp -> next;
            }
        }
        return head;
    }
}
void print(struct stu *head){
    struct stu *temp = head;
    struct po *temp_top = NULL;
    int i ;
    while (temp != NULL){
        printf("\nstudent number :%d ||student average :%.02f ||all point:%.02f ||lesson that get: %d",temp->student_number,temp->average,temp->all,temp->number_point);
        temp_top = temp -> top ;
        for (i = 1 ; temp_top != NULL;i++){
            printf("\n%d)%0.02f",i,temp_top->point);
            temp_top = temp_top->next;
        }
        temp = temp -> next;
    }
}


