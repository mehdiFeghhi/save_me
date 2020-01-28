#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct student {
    int student_number;
    struct point* po ;
    struct  student* next ;
    int count ;
    float average;
};
struct point{
    float value ;
    struct point* next ;

};
struct student* insert_point(struct student* head ,float point);
struct student* insert_student(struct student *top,int student_number);
struct student* find_ave(struct student *top);
void print(struct student*head);
int main(){
    char p[100];
//    File  *fi ;
    //fopen = ("grages.txt","r");
    char *file = "9532578 20 19 18 17.5 10\n9532880 10 0 0.25 15\n9732513 17.5 20 ";
    int j ;
    int first =  0;
    int c ;
    int i = 0 ;
    int array_counter = 0 ;
    int student_number ;
    float student_point;
    struct student *top = NULL;
    struct point *po = NULL;
    for (j = 0 ;*(file+j) != '\0';j++){
        if (*(file+j) == '\0'|| *(file+j) == '\n'){

            first = 0 ;
            p[i]= '\0';
            i = 0 ;
            student_point = atof(p);
            top = insert_point(top,student_point);
            top = find_ave(top);
        }
        else if (*(file+j) == ' '){
            if (first == 0){
                student_number = atoi(p);
                p[i] = '\0';
                i = 0 ;
                top = insert_student(top,student_number);
                first = 1 ;
            }
            else {
            p[i] = '\0';
            i = 0 ;
            student_point = atof(p);
            top = insert_point(top,student_point);
            }
        }
        else if(isdigit(*(file+j)) || *(file+j)|| '.')
            p[i++]=*(file+j) ;

    }
    print(top);
    return 0 ;
}
struct student* insert_student(struct student *top,int student_number){
    struct student *new_val = (struct student *)malloc(sizeof(struct student));
    new_val ->next = NULL;
    new_val ->po = NULL;
    struct student *temp = top;
    new_val -> student_number = student_number;
    if (top == NULL){
        return new_val;
    }
    else {
        while (top -> next != NULL)
            top = top ->next ;

        top ->next = new_val;

        return temp ;

    }
}
struct student* insert_point(struct student *top,float poi){
        struct student *temp = top ;
        struct point *head = NULL;
        struct point *add = (struct point *)malloc(sizeof(struct point));
        if (top == NULL)
            return top;
        else {
            while (temp -> next != NULL)
                temp = temp ->next;
            head = temp -> po ;
            if (head == NULL){
                add -> value = poi;
                add -> next = NULL;
                temp ->po = add;
                temp -> count = 1 ;
            }
            else {
                while (head -> next != NULL)
                        head = head ->next ;
                add -> value = poi;
                add -> next = NULL;
                head -> next = add;
                temp -> count += 1;
            }
            return top;

        }
}
struct student* find_ave(struct student *top){
        struct student *temp = top ;
        float result = 0 ;
        struct point *head ;
        struct point *add = (struct point *)malloc(sizeof(struct point));
        if (top == NULL)
            return top;
        else {
            if (temp -> next == NULL){
            head = temp -> po ;
            while (head!= NULL){
                result += head->value ;
                head = head -> next ;
                }
            temp -> average = (result / temp -> count);
            return top ;
            }
            while (temp -> next != NULL)
                temp = temp ->next;
            head = temp -> po ;
            while (head!= NULL){
                result += head->value ;
                head = head -> next ;
            }
         temp -> average = (result / temp -> count);
         return top ;
        }

}
void print(struct student *head){
    struct point *top ;
    while (head != NULL){
        printf("\nstudent number : %d  average: %.1f counter%d \n",head ->student_number,head ->average,head ->count);
        top = head ->po;
        while (top != NULL){
            printf("\n%.1f\n",top ->value);
            top = top ->next;
        }
        head = head ->next;
    }
}
