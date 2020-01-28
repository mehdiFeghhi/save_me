# include <stdio.h>
int fibo(int number);
void fibosery ();
int main(){
    fibosery();
    return 0;
}
int fibo(int number){
    if (number == 0)
        return 0;
    if (number == 1)
        return 1 ;
    else
        return fibo(number - 1) + fibo(number - 2);

}
void fibosery(){
    int result ;
    int c ;
    int number = 0;
    while ( (c = getchar()) != EOF){
        if (c <= '9' && c >= '0')
            number = number * 10 + c - '0' ;
    }
    for ( c = 0 ; c <= number ; c++){
         result = fibo(c) ;
        printf("%d\t",result) ;

    }
}
