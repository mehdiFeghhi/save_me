#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "q6_headerfile.h"
static char **A_key;// our key was puted on it
static int **A_value; // our value of our key with same index puted on it
static int size = 0 ; // size of our key and value array that mallloc
static int size_full = 0 ; // size of our key and value array that be full
void Delete_key(char key[]){
    int i ,j;
    char **new_key = (char **)malloc(sizeof(char *)* size); //make new char ** pointer for use
    int **new_value = (int **)malloc(sizeof(int *) * size); // make new int ** pointer for use
    for (i = 0 ,j = 0; i < size_full ; i++){  // copy each key and value that not equal to key of we search for it
        if (strcmp(key,A_key[i])){
            new_key[j] = A_key[i];
            new_value[j] = (int *)malloc(sizeof(int *) * size);
            *new_value[j++] = *A_value[i];
        }
    }
    size_full = j ; // update oour size_full
    A_key = new_key; // update our A_key
    A_value = new_value; // update our new_value
}
void add(char key[] , int value){
    Delete_key(key); // we dellate our rapidly key to key be uniqe
    if (size_full == 0){ // at first we make our arrays with three size
        A_key = (char **)malloc(sizeof(char)*3) ;
        A_value = (int **)malloc(sizeof(int)*3);
        size = 3 ;
    }
    else if (size_full == size){ // else all of size be full we realloc our array
        Realoc_for_add(A_key,A_value);
    }
    A_key[size_full] = key; // then we add our new key and new_Value
    A_value[size_full] = (int *)malloc(sizeof(int));
    *A_value[size_full] = value;
    size_full++;
}
void Realoc_for_add(){ // we realloc our key and value array with this function
    size += 3;
    int **new_val = NULL;
    char **new_val2 = NULL;
    A_key = my_Realloc_char(new_val2,size);
    A_value = my_Realloc_int(new_val,size);
}
char **my_Realloc_char(char **pointer ,int size){ // this function realloc new char ** pointer and pass it this function get it's value from A_key
    int i ;
    pointer = (char **)malloc(sizeof(char *) * (size));
    for (i = 0 ; i < size_full ; i++)
        pointer[i] = A_key[i];
    return pointer;

}
int ** my_Realloc_int(int **pointer , int size ){ // like Realloc_char
    int i ;
    pointer = (int **)malloc(sizeof(int *) * (size + 3));
    for (i = 0 ; i < size_full ; i++){
        pointer[i] = (int *)malloc(sizeof(int));
        *pointer[i] = *A_value[i];
    }
    return pointer;
}
void Print_List(){ // print all key with thier value
    int i ;
    for (i = 0 ; i < size_full ; i++)
        printf(" -> %s : %d\n",A_key[i],*A_value[i]);
}
void  Delete_All(int value){ // dallate all value with it's key that it's value be equal to value

 int i ,j;
    char **new_key = (char **)malloc(sizeof(char *)* size); //  I make new ** to put on it our key   that value of it not equal to value of function that give
    int **new_value = (int **)malloc(sizeof(int *) * size); //
    for (i = 0 ,j = 0; i < size_full ; i++){
        if (*A_value[i] != value){
            new_key[j] = A_key[i];
            new_value[j] = (int *)malloc(sizeof(int *) * size);
            *new_value[j++] = *A_value[i];
        }
    }
    size_full = j ; // update our size_full
    A_key = new_key; // update our key_array
    A_value = new_value; // update our key_value
}
void delete_value(int value){

int i ,j ,counter;
    char **new_key = (char **)malloc(sizeof(char *)* size); //  I make new ** to put on it our key   that value of it not equal to value of function that give
    int **new_value = (int **)malloc(sizeof(int *) * size); //
    for (i = 0 ,j = 0 , counter = 0; i < size_full ; i++){
        if (*A_value[i] != value || counter > 0){
            new_key[j] = A_key[i];
            new_value[j] = (int *)malloc(sizeof(int *) * size);
            *new_value[j++] = *A_value[i];
        }
        else
            counter++;
    }
    size_full = j ; // update our size_full
    A_key = new_key; // update our key_array
    A_value = new_value; // update our key_value
}








