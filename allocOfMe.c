# include <stdio.h>
#define  ALLOCSIZE 10000
static int full_home[ALLOCSIZE];
static int j = 0 ;
static int number = 0;
static int allocbuf[ALLOCSIZE];
static int *allocb = allocbuf ;

void shift(int index);
void sremoves(int number);
int *alloc(int n);
int find(int number);
void  afree(int *p);
void shift_right(int index);
int main(){
    full_home[0] = -1;
    int i ;
    int *p = alloc(10);
    int *d = alloc(10);
    int *s = alloc(10);
    int *y = alloc(10);
    int *w = alloc(10);
    int *r = alloc(10);
    afree(d);
    afree(s);
    afree(w);
    afree(r);
    //int *g = alloc(20);
    int *sf = alloc(5);
    int *ddd = alloc(5);
    int *xc = alloc(100);
    for (i = 0 ; full_home[i] != -1 ; i++)
        printf("\nfull home: %d",full_home[i]);
    return 0;
}

int *alloc(int n){
    int i ;
    for (i = 2 ;full_home[i] != -1 && full_home[i] != full_home[i-1] && (full_home[i] - full_home[i-1]) >= n ;i+2){
            shift_right(i);
            shift_right(i+1);
            full_home[i] = full_home[i-1] ;
            full_home[i+1]= full_home[i-1] + n;
            //full_home[i] = *allocb ;
            //full_home[i+1] = *allocb + n ;
            //allocb += n;
            j += 2 ;
            printf("\nmehdi");
            return allocbuf + full_home[i-1] ;
    }
    if (ALLOCSIZE + allocbuf - allocb >= n) {
            full_home[j++] = number;
            number += n;
            full_home[j++] = number;
            allocb = allocbuf + number;
            full_home[j] = -1;
            return allocb - n;
    }
    else
        return 0;
}
void afree(int *p){
    int number;
    if (p > allocbuf && p < allocbuf + ALLOCSIZE) {
        number = p - allocbuf ;
        sremoves(number);
    }
}
void sremoves(int number){
    int c ;
    printf("\n%d",number);
    c = find(number);
    if (full_home[c] == full_home[c+1]) {
        c += 1;
        shift(c);
        shift(c);
        j -= 2;
    }
    else {
        shift(c);
        shift(c);
        j -= 2 ;
    }
}
void shift(int index){
    printf("\nkhar");
    int i ;
    for (i = index ; i < 10000-2 ;i++)
        full_home[i] = full_home[i+1];
}
int  find(int number){
    int i;
    for (i = 0 ; full_home[i] != number ;i++);
    return i ;
}
void shift_right(int index){
    int i;
    for (i = ALLOCSIZE - 2;index <= i;i--)
        full_home[i+1] = full_home[i];
}
