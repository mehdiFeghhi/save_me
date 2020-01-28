# include <stdio.h>
#include <ctype.h>
int getname(int i);
void get_student_number(int i);
void get_point(void);
int getnumber(void);
float score[100];
float average[100];
int each_persan_have_how_much_number[100];
int student_number[100];
char name_list[1000];
int number_of_each_persan = 0 ;
int number_of_score = 0 ;
void sort(int i);
void print(int i);
void give_average_each_score(int number);
int main(){
    int std_num , number ,j ,i;
    j = number = 0 ;
    printf("How many students should I take ?\n");
    std_num = getnumber() ;
    for (i = 0 ; std_num > i ; i++){
        printf("Ok.what's the name of student Number %d \n",i+1);
        j = getname(j);
        printf("Ok.what are his/her scores?\n");
        get_point();
        printf("Student Number ?\n");
        get_student_number(i);
        printf("\nDone \n");
    }
    name_list[j] ='\0';
    give_average_each_score(std_num);
    sort(i);
    printf("\tStdNo\tAvg\n");
    print(i);
    return 0 ;
}

int getnumber(){
    int c ,result;
    result = 0 ;
    while ((c = getchar()) != EOF){
           if ( isdigit(c))
                result = result * 10 + c - '0';
           else
                break;

    }
    return result ;
}
int  getname(int i){
    int c ;
    extern char name_list[];
    while  (( c = getchar()) != EOF){
         if (c =='\n')
            break;
         else {
            name_list[i] = c ;
            i++;
            }

    }
    name_list[i] = '\n' ;
    return i+1 ;
}
void get_point(void){
    extern float score[] ;
    extern float average[] ;
    extern int each_persan_have_how_much_number[];
    float number = 0;
    float nmd = 0;
    int c , i ;
    i = 0 ;
    int j = -1;
    int number_after_dot = 1 ;
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            number = number * 10 + c - '0';
            if ( j == 0)
                number_after_dot *= 10 ;
        }
        else if ( c == '.'){
                j = 0 ;
                number_after_dot = 1 ;
        }
        else if (isspace(c) || c == '\n' ){
             score[number_of_score++] = number / number_after_dot ;
             //printf("%f\n",score[number_of_score - 1]);
            // printf("%f\n",number / number_after_dot) ;
           //  nmd = nmd + (number / number_after_dot) ;
             i++ ;
            number = 0 ;
            if (c == '\n')
                break;
        }
        else
            break;
    }
    each_persan_have_how_much_number[number_of_each_persan++] = i ;
    //printf("%d\n",each_persan_have_how_much_number[number_of_each_persan-1]);
    //average[k] = nmd / (i) ;
    //printf("%f\n",average[k]);
}
void get_student_number(int i){
    int c ;
    int number = 0 ;
    extern int student_number[];
    while ((c = getchar()) != EOF){
        if (isdigit(c))
            number = number * 10 + c - '0';
        else
            break;
    }
    student_number[i] = number;

}
void give_average_each_score(int number){
    int i , j ,n ;
    float sum ;
    n = 0 ;
    extern float average[];
    extern int each_persan_have_how_much_number[];
    extern float score[] ;
    for (i = 0 ; i < number ; i++){
        sum = 0 ;
        for (j = 0 ; j < each_persan_have_how_much_number[i] ; j++){
            //printf("%f\n",score[n]);
            sum += score[n++] ;
            //printf("%f\n",sum);
        }
        average[i] = sum / each_persan_have_how_much_number[i] ;
    }
}



void sort(int n){
    extern float average[];
    extern int student_number[];
    int i , j , helper_st;
    float helper_av ;
    for (i = 0 ; i < n-1 ; i ++)
        for( j = 0 ; j < n-i-1 ; j++)
            if (average[j] < average[j+1]){
                helper_av = average[j];
                helper_st = student_number[j];
                average[j] = average[j+1];
                average[j+1] = helper_av ;
                student_number[j] = student_number[j+1];
                student_number[j+1] = helper_st ;
            }
}
void print(int i){
    int n ;
    extern float average[];
    extern int student_number[];
    for (n = 0 ; n < i; n++){
        printf("\t%d\t%.2f\n",student_number[n],average[n]);
    }
}
