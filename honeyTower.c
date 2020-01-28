#include <stdio.h>
void honoy(int n ,char *left,char *mid ,char *right);
int main() {
    honoy(3,"left","mid","right");
    return 0;
}
void honoy(int n ,char *first,char *helper,char *destan){
    if (n == 1)
            printf("%s ---> %s\n",first,destan);
    else {
        honoy(n - 1, first, destan, helper);
        honoy(1, first, helper, destan);
        honoy(n - 1, helper, first, destan);
    }
}
