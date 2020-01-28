#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define  max 100
int how_many_student();
char *first_name[max];
char *last_name[max];
void full_list(char **first_name,char **last_name,int n);
void sort_list(char **first_name,char **last_name,int n);
void exchange(char *pinter ,char *pointer1);
int main() {
    int i ,is_end_of_file,is_get_enter,is_spacee,c,j,student;
    is_end_of_file = 1 ;
    is_get_enter = 0;
    is_spacee = 0;
    student = how_many_student();
    full_list(first_name,last_name,student);
    sort_list(first_name,last_name,student);
    return 0;
}

int how_many_student(){
    int c;
    int number = 0 ;
    printf("how many student we have ?\n");
    while ((c = getchar()) != EOF){
        if (!isdigit(c))
            break;
        else
            number = number * 10 + c - '0';
    }
    return number;
}
void sort_list(char **first_name,char **last_name,int n){
    // dar in function ma first_name ro sort miconim va last name hame motabegh first name sort minamaim

}
void full_list(char **first_name,char **last_name,int number){
    // it full first name and last name with name and last name that get from client with getchar
}
void exchange(char *pinter1 ,char *pinter2){// this function exchange place of pointer 1 and pinter2 pointer1 is biger than pointer2

}
