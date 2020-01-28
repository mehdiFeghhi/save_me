# include <stdio.h>
# include <ctype.h>
# include <math.h>
#define PI 3.14159265


int get_number(void);
float sum_angle(int number ,float angle_said_by_said_vector[]);
void line_slope(float angle_vector_arr[],int X1 ,int Y1 ,int X2,int Y2,int i,float area[]);
void find_angle(float angle_said_by_said_vector[] , float line_slope1 , float line_slope2,int i);
int  check_angle(int number , float angle_said_by_said_vector[]);
void print(char arr[]);
float calculate_area(float array[],int number);
float find_surface(int x[],int y[] , int number);
void exchange_float_to_char(float number ,char array[]);
void exchange_int_to_char(int number ,char array[]);
float pow14(int number);
int factorial(int n);
int main(){
    char exchange_int_char[100];
    float area[100], surface;
    int x_arr[100] , y_arr[100] ;
    float angle_vector_arr[100] , angle_said_by_said_vector[100];
    int i ,number ,all_of_angle_standard,all_of_angle , check,result;
    area[0] = 0 ;
    //printf("\n%.2f\n",pow14(9));
    //exchange_int_to_char(factorial(4)/(factorial(4-3) * 6) ,exchange_int_char);
    print(exchange_int_char);
    //exchange_int_to_char(5.40,exchange_int_char);
    print("enter number of vertices\n");
    number = get_number();
    all_of_angle_standard = (number -2) * 180 ;
    for (i = 0 ; i < number ; i++){
        print("\nenter the X of vertrice\n") ;
        x_arr[i] = get_number();
        print("\nenter the Y of verice\n");
        y_arr[i] = get_number();
    }
    for (i = 0 ; i < number ; i++)
        line_slope(angle_vector_arr,x_arr[i],y_arr[i],x_arr[(i+1)%number],y_arr[(i+1)%number],i,area);
   for (i = 0 ; i < number ; i++)
        find_angle(angle_said_by_said_vector,angle_vector_arr[i],angle_vector_arr[(i+1)%number],i);
   all_of_angle =(int) sum_angle(number,angle_said_by_said_vector);
   if (all_of_angle == all_of_angle_standard || all_of_angle + 1 == all_of_angle_standard || all_of_angle - 1 == all_of_angle_standard)
        check = check_angle(number,angle_said_by_said_vector);
   else {
        for (i = 0 ; i < number ; i++)
            angle_said_by_said_vector[i] = 360 - angle_said_by_said_vector[i];
        check = check_angle(number,angle_said_by_said_vector);
   }
    if (check == 1){
        print("the plygon is convex\n");
        exchange_int_to_char(factorial(number)/(factorial(number-3) * 6) ,exchange_int_char);
        print("number of tringles available\n");
        print(exchange_int_char);
    }
    else if (check == 0){
        print("the plygon is not convex");




    }
    print("\nsurface of this pyghon is \n");
    exchange_float_to_char(find_surface(x_arr , y_arr,number) , exchange_int_char);
    print(exchange_int_char);
    result = calculate_area(area ,number);
    exchange_float_to_char(result, exchange_int_char);
    print("\narea of this pyghon is \n") ;
    print(exchange_int_char);
   return 0 ;
}

int get_number(void){
    int c , number;
    number = 0 ;
    while ((c = getchar()) != EOF){
        if (isdigit(c))
            number = number * 10 + c - '0';
        else
            break ;
    }
    return number;
}
void line_slope(float angle_vector_arr[],int X1,int Y1 ,int X2 ,int Y2,int i,float area[]){
        int delta_x = X2 - X1;
        //printf("\n%d\n",delta_x);
        int delta_y = Y2 - Y1;
        //printf("\n%d\n",delta_y);
        area[i] = pow14(delta_y * delta_y + delta_x * delta_x);
        float angle = 180.0 / PI;
        if(delta_x == 0){
            if(delta_y > 0)
                angle_vector_arr[i] = 90 ;
            else if (delta_y < 0)
                angle_vector_arr[i] = 270;
            else
                print("your input is wrong please press ctrl+c to exite from program\n");
        }
        else {
            angle = angle  * atan2(delta_y , delta_x);
            if (angle < 0)
                angle = 360 + angle ;
            //printf("%.2f\n",angle);
            angle_vector_arr[i] = angle ;
        }
}
void find_angle(float angle_said_by_said_vector[],float line_slope1 ,float line_slope2,int i){
         float angle ;
         if (line_slope1 < 180)
            angle = line_slope2 - (180 + line_slope1) ;
         else
            angle = line_slope2 - (line_slope1 - 180);
         if (angle < 0 )
                angle = angle + 360 ;
         //printf("%.2f\n",angle);
         angle_said_by_said_vector[i] = angle ;
}
float sum_angle(int number ,float angle_said_by_said_vector[]){
        int i;
        float sum = 0 ;
        for (i = 0 ; i < number ;i++)
            sum += angle_said_by_said_vector[i];
        //printf("%f\n",sum);
        return sum ;
}
int check_angle(int number ,float angle_said_by_said_vector[]){
    int i ,c;
    c = 0 ;
    for(i = 0 ; i < number ; i++){
        if (angle_said_by_said_vector[i] > 180)
            c = 1;
    }
    if (c == 1)
        return 0;
    else
        return 1;
}
void print(char arr[]){
    int i = 0;
    for (i ;arr[i] != '\0';i++)
        putchar(arr[i]);
}
float pow14(int number){
    float result ,uper,down;
    if (number == 0 || number == 1)
        return number;
    down = 1;
    uper = number;
    result = (uper + down) / 2;
    while (1 > 0){
        if ((number - result * result < 0.0001  && number - result * result > 0 )|| (result * result - number < 0.0001 && result * result - number > 0 ) || number - result * result == 0)
            return result ;
        else if (number - result * result > 0){
            down = result;
            result = (down + uper) / 2 ;
        }
        else if (number - result * result  < 0 )
            uper = result ;
            result = (down + uper) / 2 ;
    }
}
void exchange_float_to_char(float number , char array[]){
    int number1 = (int) (number * 100 + 1) ;
    int reverse , j ;
    //printf("%d\n",number1);
    reverse = j = 0 ;
    while (number1 > 0){
        reverse = reverse * 10  + number1 % 10;
        number1 /= 10 ;
    }
    //printf("%d\n",reverse);
    while (reverse > 100){
        number1 = reverse % 10 ;
        array[j++] = number1 + '0' ;
        reverse = reverse / 10 ;
        }

    array[j++] = '.';
    while (reverse > 0){
        array[j++] = reverse % 10 + '0';
        reverse /= 10;
    }
    array[j] = '\0';
    //printf("%s\n",array);
}
float calculate_area(float array[] ,int number){
    int i ;
    int result = 0;
    for (i = 0 ; i < number;i++){
        printf("%.2f\n",array[i]);
        result = result + array[i];
        }
    return result ;
}
int factorial(int n){
    if (n == 0)
        return 1 ;
    return n * factorial(n-1);
}
void exchange_int_to_char(int number , char array[]){
    int reverse , j ;
    reverse = j = 0 ;
    while (number > 0){
        reverse = number % 10 ;
        number /= 10;
    }
    while (reverse > 0){
         array[j++] = reverse % 10 + '0';
         reverse /= 10 ;
    }
    array [j] = '\0';
}
float find_surface(int X[], int Y[], int n) {
    // Initialze surface
    float surface = 0.0;

    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        surface += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return (surface / 2.0) > 0 ? (surface/2.0) : (surface/2.0) * -1;
}
