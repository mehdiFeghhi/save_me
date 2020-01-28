#include <stdio.h>
#define  SIZE_OF 1000
void shift();
char *mallocf(int n);
void free(char *p);
static char allocbuf[SIZE_OF];
static char *alloc = allocbuf;
int main() {

    return 0;
}

char *mallocf(int n){
    int list_of_alloc[1000];
    list_of_alloc[0] = 0;               //the ten place of allocbuf is for me and don't get it to any poeple
    list_of_alloc[1] = 10;
    /* man dar in ghesmat miam wa age fazaieh khali byneh list_of_alloc vojod dasht gharar midam
     age faza be andazehy n vojod ndasht miam wa as Akherin koneh list_of_alloc beh bad allocsize
     beh meghdar n anjam midaham wha abteda , End list_of_alloc ro dr lisf_of_alloc grram mydaham
     manandeh [0,10,10,15,65,75,75,97]
    hamantor keh mibinid bineh5 15 ta 65 50 khaneh khali vjod dard pas mitvan agar kharber yk khaneh
     0 ta 50 bekhahd an ra azafe kondad v ma hame meghdar (allocbuf + 15) be one bramigrdanim
     yani[0,10,10,15,15,35,65,75,75,97]
     */
    return  0 ;
}
void free(char *p){
    /* agar kharbar khast khe char *p ro free coneh ma miahim wa meghdaresh ro as list_of_alloc
      hazf miconim va meghdar bahdesh ham hmin to mannadeh [0,10,10,15,35,65,75,75,97]
    */
}
void shift(){
    // be komakeh tabeh shift an meghdar keh dar list_of_alloc ro mikhahim remove miconim
}
