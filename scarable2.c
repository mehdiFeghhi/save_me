# include <stdio.h>


int main(){
    int bigger ,smaller,guess ;
    bigger = smaller = 0 ;
    int c ,i ; // variable c for get acci of char and i is counter for me that if client enter to space I break the while in line 8
    i = 0;
    printf("hello welcom to this game \n");
    printf("input your range: (make differenc betwen to number with space )\t\n");
    while  ((c = getchar()) != EOF){ // GET CHAR UNTIL C = ENTER OR C = END OF FILE
        if (c == '\n')
            break;
        else if ((c == ' ') && (++i > 1)){ // if we have more than to space we don't get number
            break;
        }
        else if ((i == 0) &&  (c <='9' && c >= '0') ){ // C was digit and space not more than 0 for first number range
            smaller = smaller * 10 + c - '0' ;
        }
        else if ((i == 1) && ( c <= '9' && c >= '0')){  // C WAS DIGIT  and space was one for get big of range
            bigger = bigger * 10 + c - '0';
        }

    }
    printf("\n");
    while ( smaller <= bigger){
        guess = (smaller + bigger) / 2 ; // it is better guess middle number
        printf("is your number %d ? < Y for yes , L for being less , B for being bigger >\n",guess);
        if ((c = getchar()) == 'L'){
            i = getchar();
            bigger = guess; // becuse our number was lower than guess  for this we take guess for bigger number range

        }
        else if (c == 'B'){
                i = getchar();
                smaller = guess; // because our number was biger than our guess of this we take gues for smaller of our range

        }
        else if (c == 'Y'){
                i = getchar();
                break ;

        }

    }
    printf("your number is %d \n",guess);

    return 0 ;
}
