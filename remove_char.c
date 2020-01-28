# include <stdio.h>
void source(char main[] , char remove[]);
void shift(char main[],int number);
int main(){
    char remove[]= "A" ;
    char main[] = "sABSdsA";
    source(main,remove);
    printf("%s",main);
    return 0 ;
}
void source(char main[] ,char remove[]){
    int i , j , helper;
    for (i = 0 ; main[i] != '\0' ; i++){
        if (main[i] == remove[0]){
            printf("ok\n");
            helper = i ;
            for (j = 0 ; remove[j] != '\0' ; j++){
               if (remove[j] != main[helper])
                    break;
               else if (remove[j+1] == '\0'){
                    printf("okk\n");
                    for (j = 0 ; remove[j] != '\0'; j++)
                        shift(main,i);
                    break;
                    }
               else {
                    helper++ ;
                    printf("okkk\n");
                }
            }
        }
    }
}

void shift(char main[],int number){
    int i ;
    printf("ok\n") ;
    for (i = number ; main[number] != '\0';i++)
        main[i] = main[i+1];
}
