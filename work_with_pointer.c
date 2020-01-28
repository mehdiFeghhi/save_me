#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void make_up(char *array1,char *array2);
int main() {
    return 0;
}
void make_up(char *array1,char *array2){
    int i ,j , count,allamat,c,gomer; // gomer bray in ast keh bedanim royeh cheh khoneh i az array2 hastiom array1 ham bray khodesh j ro dareh
    gomer = allamat = j = 0;
    char *helper = (char *)malloc(sizeof(char) * 100); // ghable az inkeh man char ham mo brizam dakhel array2 dar helper mirizam
    for (i = 0;*(array1+i) != '\0';i++) { // ta zamani keh be anteha array1 nrasisim
        if (!(isdigit(*(array1 + i))) && (*(array1 + i+1) != '.')) {
            *(helper + j) = *(array1 + i);//zamani keh a ,b ,c basheh  va bahdesh ham ... nabasheh
            j++;
            allamat = 1 ;
        }
        else if (!isdigit(*(array1 + i)) && *(array1 + i) == '.' && *(array1 + i + 1) == '.' && *(array1 + i + 2) == '.') {
            for ( count = 0; *(array1+i) + count <= * (array1 +i + 4) ;count++){
                *(helper+j) = *(array1+i)+count ;// zamani keh a ,b ,c basheh  va bahdesh ham ... basheh
                j++;                 // miam va thameh on ha hi keh beyneh shon hastab ro mirizam dakhel helper
            }
            allamat = 1;
            i += 4;
        }
        else if (isdigit(*(array1+i)) && (*(array1+i) > *(array1+i+1) || *(array1+i+1) != '.' || *(array1+i+1)!='\0'  || (!isdigit(*(array1+i+1)))))
            if (allamat) { // allamat meghe keh Aya ghable as array1+i Ayah char hayeh a b c ... bodeh ya nah
                allamat = 0;
                *(helper + j) = '\0';
                for (count = 0; count < *(array1 + i) - '0'; count++) {
                    j = 0;
                    for (c = 0; *(helper + c) != '\0'; c++) {
                        *(array2 + gomer) = *(helper + c);
                        gomer++;
                    }
                }
            }
        else if (isdigit(*(array1+1))&& (*(array1 + i) == '.')){
            for ( count = 0; *(array1+i) + count <= * (array1 +i + 4) ;count++){
                    *(helper+j) = *(array1+i)+count ;
                    j++;
                }
                i += 4;
            }

        else if (!(isdigit(*(array1 + i))) && (*(array1 + i+1) != '.') && *(array1 + i + 2)) {
            *(helper + j) = *(array1 + i);
            j++;
            allamat = 0;
        }
    }
    *(helper + j) = '\0';
    for (c = 0; *(helper + c) != '\0'; c++) {
        *(array2 + gomer) = *(helper + c);
        gomer++;
    }
    *(array2 + gomer) = '\0';
}
