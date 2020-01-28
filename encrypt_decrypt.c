# include <stdio.h>
# include <ctype.h>
void encrypt_decrypt1();
void encrypt_decrypt2();
void encrypt_decrypt3();
int main(){
    int manner,c;
    manner = 0 ;
    printf("please enter your manner that you want to choose ?\n");
    while ((c = getchar())!= EOF){
        if (isdigit(c)){
            manner = manner *  10 + c - '0';
        }
        else
            break ;
    }
    switch(manner){
        case (1):
            encrypt_decrypt1();
            break;
        case (2):
            encrypt_decrypt2();
            break;
        case (3):
            encrypt_decrypt3();
            break ;
        default:
            printf("we have'nt patern %d",manner);
            break ;
    }
    return 0 ;
}
void encrypt_decrypt2(){
    int c , key , chose_way , number ,i ,j,helper ;
    chose_way = key = i = j = helper = 0 ;
    char text[1000] , encoder[1000] , decoder[1000];
    printf("enter your key :\n");
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            key = key * 10 + c - '0';
        }
        else
            break;
    }
    printf(" if you want to decrypt yout text enter 2 else if you want to encrypt your text enter 1: ");
    while ((c = getchar()) != EOF){
            if (isdigit(c))
                chose_way = chose_way * 10 + c - '0';
            else
                break ;
    }
    switch(chose_way){
        case (1):
            printf("\nenter your text encrypt: ");
            while ((c = getchar()) != EOF){
                text[i] = c ;
                i++ ;
            }
            text[i] = '\0';
            for (number = 0 ; number < key ; number++){
                for ( i = 0 ; text[i] != '\0';i++){
                    if ((i % key) == number){
                        encoder[j] = text[i];
                        j++ ;
                    }
                }
            }
            encoder[j] = '\0';
            printf("\nencrypt this text is : %s",encoder);
            break ;
        case (2):
            printf("\n enter your text you want do decrypt it: ");
            while ((c = getchar()) != EOF){
                text[i] = c ;
                i++;
            }
            text[i] = '\0';
            for (number = 0 ; number < key ; number++)
                for (helper = 0 ; helper * key + number < i ; helper++)
                    decoder[helper * key + number] = text[j++];
            decoder[j] = '\0';
            printf("\nyour decoter of this text:  %s",decoder);
            break ;
        default :
            printf("your input is wrong\n");
            break ;

        }


}
void encrypt_decrypt1(){
     int c , key , chose_way , i , j,helper;
     char text[1000] , encoder[1000] , decoder[1000];

    chose_way = key = i = j = 0 ;
    printf("enter your key :\n");
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            key = key * 10 + c - '0';
        }
        else
            break;
    }
    printf(" if you want to decrypt yout text enter 2 else if you want to encrypt your text enter 1:    ");
    while ((c = getchar()) != EOF){
            if (isdigit(c))
                chose_way = chose_way * 10 + c - '0';
            else
                break ;
    }
    switch(chose_way){
        case (1):
            printf("\nenter your text : ");
            while ((text[i] = getchar()) != EOF)
                    i++;
            text[i] = '\0';
            for (; j < i - 1 ; j++)
                encoder[j] = (text[j] + key) % 126;
            encoder[j] = '\0';
            printf("\nyour encrypted of this text: %s",encoder);
            break ;
        case (2):
            printf("\nenter your text : \t");
            while (((text[i]) = getchar()) != EOF)
                    i++;
            text[i] = '\0';
            printf("\n");
            for (; j < i ; j++){
                helper = text[j] - key ;
                if (helper < 0){
                    helper = helper * -1;
                    helper = helper % 126;
                    helper = 126 - helper;
                }
                decoder[j] = helper ;
            }
            decoder[j] = '\0';
            printf("\nyour decrypted of this text:  %s",decoder);
            break ;

        default :
            printf("\nyour input is wrong\n");
            break ;

        }



}
void encrypt_decrypt3(){
     int i , j, c , key1,key2 , chose_way, number,helper ;
    chose_way = key1 = key2 = helper = i = 0 ;
    char text[1000] , encoder1[1000],decoder1[1000],encoder2[1000],decoder2[1000];
    printf("enter your first key : ");
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            key1 = key1 * 10 + c - '0';
        }
        else
            break;
    }
    printf("\nenter the seceond key: ");
    while ((c = getchar()) != EOF){
        if (isdigit(c)){
            key2 = key2 * 10 + c - '0';
        }
        else
            break ;
    }
    printf("\nif you want to decrypt yout text enter 2 else if you want to encrypt your text enter 1: ");
    while ((c = getchar()) != EOF){
            if (isdigit(c))
                chose_way = chose_way * 10 + c - '0';
            else
                break ;
    }
    switch(chose_way){
        case (1):
            printf("\nenter raw text: ");
            while ((text[i] = getchar()) != EOF)
                    i++;
            text[i] = '\0';
            for (j = 0; j < i ; j++)
                encoder1[j] = (text[j] + key1) % 126;
            encoder1[j] = '\0';
            j = 0 ;
            for (number = 0 ; number < key2 ; number++){
                for ( i = 0 ; encoder1[i] != '\0';i++){
                    if ((i % key2) == number)
                        encoder2[j++] = encoder1[i];
                }
            }
            encoder2[j] = '\0';
            printf("\nencrypted text:%s\n",encoder2);
            break ;
        case (2):
            printf("\n enter your text you want do decrypt it: ");
            while ((c = getchar()) != EOF){
                text[i] = c ;
                i++;
            }
            text[i] = '\0';
            j = 0 ;
            for (number = 0 ; number < key2 ; number++)
                for (helper = 0 ; helper * key2 + number < i ;helper++)
                        decoder1[helper * key2 + number] = text[j++];
            decoder1[j] = '\0';
            for (j = 0; j < i  ; j++){
                helper = decoder1[j] - key1 ;
                if (helper < 0){
                    helper = helper * -1;
                    helper = helper % 126;
                    helper = 126 - helper;
                }
                decoder2[j] = helper ;
            }
            decoder2[j] = '\0';
            printf("\ndecrypted text: %s \n",decoder2);
            break ;
        default :
            printf("your input is wrong\n");
            break ;
        }
}
