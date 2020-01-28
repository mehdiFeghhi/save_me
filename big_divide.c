#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char *number);
void big_add(char *number1,char *number2,char *result);
//void senfice(char *result,char *result1);
void big_sub(char *number1 ,char *number2 ,char *result);
void big_divide(char *number1 , char *number2 , char *result);
int  big_min(char *number ,char *number2);
int biger(char *number ,char *number2);
int main() {
  char number[1000] = "6531";
  char number2[1000] = "102";
  char *result  = (char *)malloc(sizeof(char)*1000);
  big_divide(number,number2,result);
  printf("%s\n",result);
  return 0;
}
void big_divide(char *number ,char *number2,char *result){
    char *helepr = (char *)malloc(sizeof(char)*1000);
    char *one = (char *)malloc(sizeof(char) * 1000);
    char *result_fake = (char *)malloc(sizeof(char) *1000);
    *one = '1';
    *helepr = '0';
    *(helepr+1)= '\0';
    *(one+1) = '\0';
    *result_fake = '0';
    *(result_fake+1) = '\0';
    //big_add(helepr,one,result_fake);
    strcpy(helepr, result_fake);
    //printf("\n%s",result_fake);
    for (; big_min(number,number2);big_add(helepr,one,result_fake)){
        strcpy(helepr, result_fake);
        reverse(one);
    }
    strcpy(result,result_fake);
}
int big_min(char *number1 , char *number2 ){
    char *resutltd = (char *)malloc(sizeof(char) * 1000);
    int i ,j ,allamat;
    allamat = i = j = 0 ;
    if (biger(number2 ,number1)) {
        allamat = 1;
        return 0;
    }
    else {
        //printf("%s\n",number1);
        //printf("%s\n",number2);
        big_sub(number1,number2,resutltd);
        reverse(number2);
        strcpy(number1,resutltd);
        //printf("%s\n",number1);
        return 1;
    }

}
int biger(char *number2 ,char  *number1){
    if (strlen(number2) > strlen(number1))
        return 1;
    else if (strlen(number2) == strlen(number1))
        if (strcmp(number2 ,number1) == 1)
            return 1;
    return 0;
}
void big_add(char *number1,char *number2,char *result) {
    int i ,smaller ,helper;
    char *result2 = (char *)malloc(sizeof(char) * 10000);
    if (*number1 != '-' && *number2 != '-' ) {
        reverse(number1); // reverse the string
        reverse(number2);
        for (i = 0; *(number1 + i) != '\0' && smaller == 0 ; i++) {
            if (*(number1 + i) + *(number2 + i) - '0' > '9') {
                if (*(number1+i+1) == '\0') {
                    *(number1 + i + 1) ='1';
                    *(result + i) = *(number1 + i) + *(number2 + i) - (10+'0');
                    *(number1+i+2) = '\0';
                }
                else{
                    *(number1 + i + 1) = *(number1 + 1 + i) + 1;
                    *(result + i) = *(number1 + i) + *(number2 + i) - (10 + '0');
                }

            } else
                *(result + i) = *(number1 + i) + *(number2 + i) - '0';
            if (*(number2+i+1) == '\0')
                smaller = 1;
        }
        for (i;*(number1+i) != '\0' && smaller == 1;i++)
            *(result+i) = *(number1+i);

        *(result+i) = '\0';
        reverse(result);
        //printf("%s\n",result);
    }
    else if (*number1 == '-' && *number2 == '-' ){
        reverse(number1);
        reverse(number2);
        for (i = 0; *(number1 + i) != '-' && smaller == 0; i++) {

            if (*(number1 + i) + *(number2 + i) - '0' > '9') {
                if (*(number1+i+1) == '-') {
                    *(number1 + i + 1) ='1';
                    *(result + i) = *(number1 + i) + *(number2 + i) - (10 + '0');
                    *(number1+i+2) = '-';
                    *(number1+i+3) = '\0';
                }
                else {
                    *(number1 + i + 1) = *(number1 + 1 + i) + 1;
                    *(result + i) = (*(number1 + i) + *(number2 + i)) - ('0'+10);
                }
            } else
                *(result + i) = *(number1 + i) + *(number2 + i) - '0';
            if (*(number2+i+1) == '-')
                smaller = 1;

        }
        for (i;*(number1+i) != '-' && smaller == 1;i++)
            *(result+i) = *(number1+i);

        *(result+i) = '-';
        *(result+i+1) = '\0';
        reverse(result);
        printf("%s\n",result);
    }
    else if (*number1 != '-' && *number2 == '-' ){
        big_sub(number1,number2+1,result);

    }
    else {
        big_sub(number2,number1+1,result);
    }
    //printf("%s\n",result);
    //senfice(result,result2);
    //strcpy(result,result2); //copy result to result2

}
void reverse(char *number) {
    int n = strlen(number)-1;
    int i ;
    char temp ;
    for (i = 0 ; i < n ; n-- , i++) {
        temp = *(number + n);
        *(number+n) = *(number+i);
        *(number + i) = temp ;
    }
}
/*void senfice(char *result ,char *result2){//make the number
    int i = 0 ;
    int j = 0 ;
    reverse(result);

    while (*result++ == '0')
        j++;
    *result--;
    while (*result!= '\0') {
        *(result2++) = *(result++);
        i++;
    }

    *(result2) = '\0';
    reverse(result2-i);
    //printf("%s\n",result2-i);
    *(result2) = 'e';
    *(result2+1) = j + '0';
    *(result2+2) = '\0';
}
*/
void big_sub(char *number1 , char *number2 ,char *resutlt){
    int i ,j ,allamat;
    allamat = i = j = 0 ;
    if (biger(number2 ,number1) ) {
        *resutlt = '-';
        big_sub(number2,number1,resutlt);
    }
    else {
        if (*resutlt == '-') {
            allamat = 1;
        }
        reverse(number1);
        reverse(number2);
        for (;*number2 != '\0';number2++,number1++,i++) {
            if (*number1 >= *number2)
                *(resutlt+i) = *number1 - *number2 + '0';
            else{
                *(resutlt+i) = *number1 + 10 - *number2 + '0';
                for (j = 1 ; *(number1+j) == '0' ; j++) {
                    *(number1 + j) = '9';
                    //printf("ok\n");
                }
                *(number1+j) -= 1;
            }
        }
        for (;*number1 != '\0';i++)
            *(resutlt+i) = *number1++;
        i--;
        for (;*(resutlt+i) == '0';i--);
        if (allamat == 1){
            i++;
            *(resutlt + i) = '-';
            i++;
            *(resutlt + i) = '\0';
            //printf("%d\n",i);
        }
        else {
            i++;
            *(resutlt + i) = '\0';
        }
        reverse(resutlt);
    }

}
