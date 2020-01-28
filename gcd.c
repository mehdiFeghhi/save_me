# include <stdio.h>
# include <ctype.h>
int give_gcd_n(int arr[],int number);
int give_lcd(int arr[],int number,int gcd);
int give_gcd_two(int number1 ,int number2);
int main(){
    int arr[] = {2,4,8};
    int gcd , lcd ;
   /* int i , gcd , lcm ,c , number,n ;
    c = 0 ;
    int arr[1000] ;
    printf("how many number you want to get us/\n");
    while (isdigit(c = getchar())){
        c = c * 10 +  c - '0';
    }
    for ( i = 0 ; i < n ; i++){
        number = 0 ;
        while (( c = getchar()) != EOF){
            if (isdigit(c))
                number = number * 10 + c -'0';
            else
                break ;
        }
    }
   */
    gcd = give_gcd_n(arr,3);
    printf("%d\n",gcd);
    lcd = give_lcd(arr,3,gcd);
    printf("the gcd is %d and lcd is %d\n",gcd, lcd);
    return 0 ;
}
int give_gcd_n(int arr[],int number){
    int first_number = arr[0];
    int i ;
    for (i ; i < number ; i++){
            first_number = give_gcd_two(first_number,arr[i]);
    }
    return first_number ;

}
int give_lcd(int arr[],int number ,int gcd){
    int mul = 1;
    int i ;
    for(i = 0 ;i < number ;i++){
         mul = (mul * arr[i]) / gcd ;
    }
    return mul  ;
}
int give_gcd_two(int number1 , int number2){
    int min;
    min = (number1 < number2) ? number1 : number2 ;
    while (min > 1){
        if (((number1 % min) == 0) && ((number2 % min) == 0) )
            return min;
        else
            min--;

    }
    return 1;
}
