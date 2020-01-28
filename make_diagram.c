# include <stdio.h>
# include <ctype.h>
char ground[10101]; // ground that we want to show train
void print(char arr[]); // for your forbidan that we must'nt use printf I forced to use this function that use putchar
void where_train(int arr[],int number); // this function taken ABCD number to (AB, CD)
void make_int_number_to_char(int number ,char arr[]);// make int number to char arr of it number
void reverse(char arr[] ,  int number);// make reverse of each char arr[]
void find_distance(int number , int arr[],float distance[]);// find distance each train
float square(int result);
int main(){

    extern char ground[];
    float distance[100];
    char pr[1000];
    int i , number ,c,j,k;
    number = 0 ;
    int arr[100];
    for ( i = 1 ; i <= 10000 ; i++){
        if (i % 100 == 0){
            ground[i-1] = '\n'; // make wall of ground
        }
        else {
            ground[i-1] = ' '; // make the ground clean for user to see
        }
    }
    ground[i-1] = '\0';
    print("enter how many train we have?\n");
    while ((c = getchar()) != EOF){
         if (isdigit(c))
            number =  number * 10 + c - '0'; // make number of train
         else
            break;
        }
    for (j = 0 ;  j < number ; j++) // praper arr for number of each location that give from client
        arr[j] = 0 ;
    for (j = 0 ; j < number ; j++){
        print("\nEnter number");
        make_int_number_to_char(j+1,pr);
        print(pr);
        print("\n");
        for (k = 0 ; k < 4 ; k++){
                if (isdigit(c = getchar())){
                    arr[j] = arr[j] * 10 + c - '0';// make number ABCD

                }
                else if(c =='\n' && k == 4)
                    break ;
                else {
                    print("input not correct.\n");
                    k--;
                }
        }
    }
    print("\n");
    where_train(arr,number);
    print(ground);
    find_distance(number ,arr , distance); //find distance betwean each train
    print("yes");

    return 0 ;


}
void  where_train(int arr[],int number){
    extern char ground[];
    int i ,x ,y;
    for (i = 0 ; i < number ; i++){
        printf("%d\n",arr[i]);
        x = arr[i] / 100;
        y = arr[i] % 100;
        ground[10100 - (y * 100) + x] = 'A' + i ; // put coordinait of each point in ground
        ground[10100 - (y * 100) + x + 1] = '(';
        ground[10100 - (y * 100) + x + 2] = x / 10 + '0' ;
        ground[10100 - (y * 100) + x + 3] = x % 10 + '0';
        ground[10100 - (y * 100) + x + 4] = ',';
        ground[10100 - (y * 100) + x + 5] = y / 10 + '0';
        ground[10100 - (y * 100) + x + 6] = y % 10 + '0';
        ground[10100 - (y * 100) + x + 7] = ')';
    }
}
void print(char arr[]){
    int i = 0;
    for (i ;arr[i] != '\0';i++)
        putchar(arr[i]);

}
void make_int_number_to_char(int number , char arr[]){
    int i ;
    for ( i = 0 ; number > 0 ; i++){
        arr[i] = number % 10 ;
        number /= 10 ;
    }
    arr[i] = '\0';
    reverse(arr,i-1);
}
void reverse(char arr[],int number){
    int i ;
    char helper ;
    for (i = 0 ; i > number ; i++){
        helper =  arr[number];
        arr[number] = arr[i];
        arr[i] = helper;
        number--;
    }
    arr[i] = '\0';
}
void find_distance(int number , int arr[],float distance[]){
    int i, j, x1 , x2 ,y1 ,y2, result;
    int r = 0 ;
    for(i = 0 ; i < number - 1 ; i++){
        x1 = arr[i] /100 ;
        y1 = arr[i] % 100 ;
        for (j = i ; j < number ; j++){
            x2 = arr[j] / 100 ;
            y2 = arr[j] % 100 ;
            result = (y2-y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
            distance[r++] = square(result);
            }
    }
}
float square(int x){
    int mide , sub ,sup ;
    if (x == 0 || x == 1)
        return x;
    sub = 1 ;
    sup = x ;
    mide = (sub + sup) / 2 ;
    while (x - (mide * mide) > 0.0001 || x - (mide * mide) < - 0.0001){
            if ( x > mide * mide){
                    sub = mide ;
                    mide = (sub + sup) / 2 ;
            }
            else
                    sup = mide ;
                    mide = (sub + sup) / 2 ;
    }
    return mide;
}


