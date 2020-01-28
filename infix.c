#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 1000
void infix_to_postfix(char *infix, char *postfix);

float postfix_eval(char *postfix);
void push_float(float a);
void push_char(char a);
float calcu(float number1,float number2,char op);
float pop_float();
char pop_char();
int is_op(char a);
int is_empty_char_stack();
float stack_float[max];
int gomer_stack_float = 0 ;
char stack_char[max];
int gomer_stack_char = 0 ;
int main() {
    char infix[] = "2.5+4.1*(3.01-1.2)";
    char postfix[1000];
    infix_to_postfix(infix,postfix);
    float cal = postfix_eval(postfix);
    printf("\n%s\n",postfix);
    printf("result is %.2f\n",cal);
    return 0;
}

void infix_to_postfix(char *infix, char *postfix) {
    int i, j;
    j = 0;
    for (i = 0; *(infix + i) != '\0'; i++) {
        if (is_op(*(infix+i))) {
            push_char(*(infix + i));
            *(postfix+j) = ' ';
            j++;
        }
        else if (isdigit(*(infix + i)) || isspace(*(infix + i)) || (*(infix+i) == '.')) {
            *(postfix + j) = *(infix + i);
            j++;
        } else if (*(infix + i) == ')') {
            for (; !is_empty_char_stack(); j++)
                *(postfix + j) = pop_char();
        }
    }
    for (; !is_empty_char_stack();j++)
        *(postfix + j) = pop_char();
    *(postfix+j) ='\0';
}

void push_char(char a) {
    extern char stack_char[];
    extern int gomer_stack_char;
    if (gomer_stack_char < max)
        stack_char[gomer_stack_char++] = a ;
    else
        printf("your stack is full\n");
}

char pop_char() {
    extern char stack_char[];
    extern int gomer_stack_char;
    if (gomer_stack_char > 0)
        return stack_char[--gomer_stack_char];
    else
        printf("your stack is empty!!!!!!\n ");
    return 0;
}
int is_empty_char_stack(){
    extern int gomer_stack_char;
    if (gomer_stack_char == 0)
        return 1;
    return 0;
}
float postfix_eval(char *postfix){
    int i , helper;
    float number1,number2;
    char *number = (char *)malloc(sizeof(char) * 1000);
    for (i = 0 ; *(postfix+i) != '\0';i++){
        if(isdigit(*(postfix+i))){
            helper = 0;
            for(;isdigit(*(postfix+i)) || *(postfix+i) == '.';i++){
                *(number+helper) = *(postfix+i);
                helper++;
            }
            *(number+helper) = '\0';
            push_float(atof(number));
            i--;
        }
        else if(is_op(*(postfix+i))){
            number1 = pop_float();
            number2 = pop_float();
            printf("%f\n",calcu(number1,number2,*(postfix+i)));
            push_float(calcu(number1,number2,*(postfix+i)));

        }

    }
    return pop_float();

}
int is_op(char a) {
    if (a == '*' || a == '-' || a == '/' || a == '+')
        return 1;
    return 0;
}
float pop_float(){
    extern float stack_float[];
    extern int gomer_stack_float ;
    if (gomer_stack_float > 0)
        return stack_float[--gomer_stack_float];
    printf("your stack is empty\n");
    return 0;
}
void push_float(float a){
    extern float stack_float[];
    extern int gomer_stack_float;
    printf("%f\n",a);
    if (gomer_stack_float < max)
        stack_float[gomer_stack_float++] = a;
    else
        printf("\nyour stack is full");
}
float calcu(float number1,float number2,char op){
    switch (op){
        case '-':
            return number2 - number1;
        case '*':
            return number2 * number1 ;
        case '+':
            return number2 + number1;
        case '/':
            if (number1 != 0)
                return number2 / number1 ;
            printf("\nWarnig you give me zero for div  at number two its wrong I give you wrong number of 0\n");
            return 0;
        default:
      printf("\nyour op is wrong \n");
    }
   /* if (op == '+')
        return (number1 + number2) ;
    else if (op == '*')
        return (number1 * number2) ;
    else if (op == '/')
        return  (number2 / number1);
    else if (op == '-');
    return (number2 - number1) ;*/
}
