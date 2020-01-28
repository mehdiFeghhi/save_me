# include <stdio.h>
# include <ctype.h>
# include <string.h>
int compare(char Num[] ,int N);
int main(){
    char number1 [1000];
    int number2 , c ,output ,i;
    i = number2 = 0 ;
    printf("Enter main number:\n");
    while ((c = getchar()) != EOF){
        if (isdigit(c))
            number1[i++] =  c;
        else
            break;
    }
    number1 [i] = '\0';
    printf("Enter secend number : \n");
    while ((c = getchar())!= EOF){
        if (isdigit(c))
            number2 = number2 * 10 + c - '0';
        else
            break;
    }
    output = compare(number1,number2);
    printf("%d\n",output);
    return 0;
}
int compare(char Num[] ,int N){
    int first_number , secend_number,i;
    first_number = secend_number = 0 ;
    for (i = 0 ; i < N ; i++)
        first_number = first_number * 10 + Num[i] - '0';
    printf("%d\n",first_number);
    i = strlen(Num)-N;
    while (Num[i] != '\0'){
        secend_number = secend_number * 10 + Num[i] - '0';
        i++;

    }
    printf("%d\n",secend_number);
   return first_number - secend_number;
}
