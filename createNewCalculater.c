#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define Size_of 1000
char stack[1000];
int  stack_int[1000];
int full_stack = 0 ;
int full_stack_int = 0 ;
void make_curve(char *p);
int calculate(char *p, int x);
void make_postfixe(char *p,char f[]);
int pop();
void push(int c);
void push_int(int c);
void print(char **array,int size);
int  pop_int();
int pow_e(int addad,int n);
int main(){

    make_curve("Y=(2X)^2");
    return 0 ;

}
void make_curve(char *p){
    int i ,j;
    int c ;
    char f[1000];
    char **array = (char **)malloc(sizeof(char*)*100);
    for (i = 0 ; i <= 100 ; i++)
        *(array+i) = (char *)malloc(sizeof(char)*100);
    make_postfixe(p,f);
    //printf("%s\n",p);
    for (i = 0 ; i <= 100 ;i++)
        for (j = 0 ; j <= 100; j++)
            array[i][j] = ' ';
   for (i = 0 ;((c = calculate(f,i)) <= 100 ) && i <= 100 ; i++){
       array[i][c] = '*';
       }
   print(array,100);
}
void make_postfixe(char *p,char array[]){
    int i ,j,get_number;
    extern int full_stack;
    get_number = j = 0 ;
    int get_two_number_first = 0 ;
    for (i = 0 ; *(p+i) != '\0';i++){
        if ((isdigit(*(p+i)) || *(p+i) == 'X')){
            array[j] = *(p+i);
            j++;
            if( (i - 1 >= 0 ) && isdigit(*(p+i-1)))
                push('*');

        }
        else if ( *(p+i) == '*' || *(p+i) == '+' || *(p+i) == '-' || *(p+i) == '/' || *(p+i) == '^')
            push(*(p+i));
        else if (*(p+i) == ')'){
            while (full_stack){
                array[j] = pop();
                j++;
            }

        }

    }
    while (full_stack){
        array[j] = pop();
        j++;
    }
    array[j] = '\0';
}
int calculate(char *p, int c){
    int i ;
    int first ;
    int secent;
    for ( i = 0 ; *(p+i) != '\0' ; i++){
        if (*(p+i) == '*' || *(p+i) == '+' || *(p+i) == '-' || *(p+i) == '/' || *(p+i) == '^'){
            first = pop_int();
            secent = pop_int();
            if (*(p+i) == '*' ){
                push_int(first * secent);}
            else if ( *(p+i) == '+' ){
                push_int(first + secent);}
            else if (*(p+i) == '-' ){
                push_int(secent - first);}
            else if (*(p+i) == '/' ){
                push_int(secent / first);}
            else if (*(p+i) == '^'){
                push_int(pow_e(secent,first));}
            }
        else if (*(p+i) == 'X')
                push_int(c);
        else if (isdigit(*(p+i)))
                push_int(*(p+i)-'0');
    }
    int cc = pop_int() ;
    //printf("%d",cc = pop_int());
    return cc;
}
int pow_e(int addad,int n){
        int i ;
        int result = 1 ;
        for (i = 0 ; i < n ; i++)
            result = result * addad;
        return result ;
}
void push(int c){

    extern char stack[];
    extern int full_stack;
    if (Size_of - 1 >  full_stack){
        stack[full_stack] = c ;
        full_stack++;
    }
    else
        printf("stack is full");
    return ;
}
int pop(){
    extern char stack[];
    extern int full_stack;
    int c ;
    if(full_stack != 0){
        full_stack--;
        c = stack[full_stack];
        return c ;
    }
    printf("stack is empty ");
    return 0 ;
}
void push_int(int c){
    extern int stack_int[];
    extern int full_stack_int;
    if (Size_of > full_stack_int){
        stack_int[full_stack_int] = c ;
        full_stack_int++;
        return ;
    }
    else
       printf("stack is eeeee full");
    return ;
}
int pop_int(){
    extern int stack_int[];
    extern int full_stack_int;
    int c ;
    if (full_stack_int != 0){
        full_stack_int--;
        c = stack_int[full_stack_int];
        return c ;
    }
    printf("stack is empty");
    return 0;

}
void print(char **array,int size){
    int i , j;
    for (i = size; i >= 0 ; i--)
        printf("%s\n",*(array+i));
}
