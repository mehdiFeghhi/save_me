#include <stdio.h>
#include <ctype.h>

int stack[1000];
#define  SIZE_OF 1000
int i = 0;

int evalute_prefix_boolean_expersion(char c[]);

int stack_isnt_empty();

int is_op(char a);

void push(char s);

void make_boolean_expersion_to_prefix(char c[], char g[]);

char pop();

int pop_int();

void push_int();

int main() {
    char c[] = "(~1 | 1) | 0";
    char v[1000];
    make_boolean_expersion_to_prefix(c, v);
    printf("\n%s", v);
    int h = evalute_prefix_boolean_expersion(v);
    printf("\n%d",h);
    return 0;
}

void make_boolean_expersion_to_prefix(char array[], char copy[]) {
    int i;
    int j = 0;
    int is_exit_op = 0;
    for (i = 0; array[i] != '\0'; i++) {
        if (isdigit(array[i]))
            copy[j++] = array[i];
        else if (is_op(array[i])) {
            push(array[i]);
            printf("\n%c", array[i]);
        } else if (array[i] == ')')
            while (stack_isnt_empty())
                copy[j++] = pop();
        else if (array[i] == '~') {
            copy[j++] = array[i + 1];
            copy[j++] = array[i];
            i++;
        }

    }
    while (stack_isnt_empty())
        copy[j++] = pop();
    copy[j] = '\0';
}

int evalute_prefix_boolean_expersion(char prefix[]) {
    int i;
    int number1, number2;
    for (i = 0; prefix[i] != '\0'; i++) {
        if (isdigit(prefix[i]))
            push_int(prefix[i] - '0');
        else if (is_op(prefix[i])) {
            number1 = pop_int();
            number2 = pop_int();
            switch (prefix[i]) {
                case '|':
                    push_int(number1 | number2);
                    break;
                case '&':
                    push_int(number1 & number2);
                    break;
            }
        } else if (prefix[i] == '~') {
            number1 = pop();
            if (number1 == 1)
                push_int(0);
            else
                push_int(1);
        }
    }
    return pop_int();
}

void push(char a) {
    extern int i, stack[];
    if (i < SIZE_OF)
        stack[i++] = a;
    else
        printf("\nyour stack is full");
}

char pop() {
    extern int i, stack[];
    if (i > 0)
        return stack[--i];
    printf("\nyour stack is empty");
    return 0;
}

int stack_isnt_empty() {
    extern int i;
    if (i > 0)
        return 1;
    return 0;
}

int is_op(char s) {
    if (s == '|' || s == '&')
        return 1;
    return 0;
}

void push_int(int a) {
    extern int i, stack[];
    if (i < SIZE_OF)
        stack[i++] = a;
    else
        printf("\nyour stack is full");
}

int pop_int() {
    extern int i, stack[];
    if (i > 0)
        return stack[--i];
    printf("\nyour stack is empty");
    return 0;
}
