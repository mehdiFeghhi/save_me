# include <stdio.h>
# include <ctype.h>
void data_maining(char arr[]);
void shift(char arr[],int number);
void data_maining_of_digit(char arr[]);
int make_number(char arr[] , int arr2[]) ;
int sum(int arr2[],int number);
int main (){
    int i , c ,number_of_people,sum_of_their_age ;
    float average_of_their_age;
    char arr[1000];
    int arr2[100];
    i = number_of_people = sum_of_their_age = average_of_their_age = 0 ;
    while ((c = getchar())!= EOF)
        arr[i++] = c ;
    printf("\nOk \n");
    arr[i] = '\0';
    data_maining(arr);
    printf("%s\n",arr);
    data_maining_of_digit(arr);
    printf("%s\n",arr);
    number_of_people = make_number(arr,arr2);
    sum_of_their_age = sum(arr2,number_of_people);
    average_of_their_age = sum_of_their_age / number_of_people ;
    printf("number of people : %d\n",number_of_people);
    printf("sum of their age: %d\n",sum_of_their_age);
    printf("average of ther age %.2f\n",average_of_their_age);
    return 0 ;
}
void data_maining(char arr[]){
    int i = 0;
    int check = 0 ;
    while (arr[i] != '\0') {
        if (arr[i] == 'A'  && arr[i+1] == 'g' && arr[i+2] == 'e' && arr[i+3] ==':'){
                i += 4 ;
                while(isspace(arr[i])){
                    i++;
                }
                while (isdigit(arr[i])){
                    i++;
                }
                check = 1 ;
            }
        else if (check == 0){
                shift(arr ,i+1);
                }
        else if(check == 1){
            arr[i] = '\n';
            i++;
            check = 0 ;
            }
    }
    arr[i] = '\0';

}
void shift(char arr[],int number){
    int i ;
    for (i = number ; arr[i] != '\0' ; i++ ){
            arr[i-1] = arr[i];

    }
    arr[i-1] = '\0';
}
void data_maining_of_digit(char arr[]){
    int i = 0;
    while (arr[i] != '\0'){
        if(arr[i] == '\n' || isdigit(arr[i]))
            i++ ;
        else
            shift(arr,i+1);
    }
}
int sum(int arr[],int number){
    int i;
    int sum = 0 ;
    for (i = 0 ; i < number ; i++)
        sum += arr[i];
    return sum;
}
int make_number(char arr[],int arr2[]){
    int i , j ,number , conter;
    conter = j = number = 0 ;
    for (i = 0 ; arr[i] != '\0' ; i++){
        if (arr[i] == '\n' && isdigit(arr[i+1])){
            conter++;
            arr2[j++] = number ;
            number = 0 ;
        }
        else if (isdigit(arr[i]))
            number = number * 10 + arr[i] - '0';
    }
    arr2[j] = number ;
    return conter+1 ;
}
