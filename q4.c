#include <stdio.h>
#include <stdlib.h>
char *strsplit(char *source,char *separators);
int main() {
    char *a = (char *)malloc(sizeof(char) * 1000);
    return 0;
}
char *strsplit(char *source,char *separators){
    int i ,j,gomer,helper;
    gomer = 0 ;
    char *result = (char *)malloc(sizeof(char) * 1000);
    for(i = 0 ; *(source+i) != '\0';i++){
        if (*(source+i) == *(separators)){
            helper = 0 ;
            for (j = 0; *(source + i + j) == *(separators + j); j++) {
                if (*(separators + j + 1) == '\0') {
                    *(result + gomer) = ' ';
                    helper = 1;
                    break;
                }

            }
            if (helper == 1) {
                i += j ;
                gomer++;
            }
            else {
                *(result + gomer) = *(source+i);
            }

        }
        else {
            *(result+gomer) = *(source+i);
            gomer++;
        }


    }
    *(result+gomer) = '\0';
    return result;
}
