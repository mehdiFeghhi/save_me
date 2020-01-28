#include <stdio.h>
#include <math.h>


void PowerSet(int set[], int size){
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    int next_size = (int)pow(2, size);
    int conter, j , stution ;
    for(conter = 0; conter < next_size; conter++){
        stution = 0 ;
        for(j = 0; j < size ; j++){
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
            if(conter & (1<<j)){
                if (stution == 0){
                    printf(",{%d", set[j]);
                    stution = 1 ;
                }
                else
                    printf(",%d",set[j]);
            }
       }
       if (conter == 0 && j == size)
            printf("{null");
       else
            printf("}");
    }
    printf("}");
}
/*Driver program to test printPowerSet*/
int main(){
    int set[] = {1,2,3,4};
    PowerSet(set, 4);
    return 0;
}

