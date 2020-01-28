#include <stdio.h>
#include <stdlib.h>
void mat_add(int *mat1[],int mat1_rows,int mat1_cols,int *mat2[],int mat2_rows,int mat2_cols,int *mat_res[]);
void mat_mult(int *mat1[],int mat1_rows,int mat1_cols, int *mat2[],int mat2_rows,int mat2_cols,int *mat_res[]);
void mat_transpose(int *mat[],int mat_rows,int mat_cols,int *mat_res[]);
int *make_row(int **mat1,int i , int mat1_cols);
int *make_cols(int **mat2,int mat2_rows,int j);
int zarb(int *arr_first,int *arr_secend,int  size);
void print_matric(int *mat[],int row,int col);
void print(int *p ,int size);
int main(){
    int *res[2];
    res[0] = (int *)malloc(sizeof(int) *2);
    *res[0] = 1;
    *(res[0]+1) = 2;
    res[1] =(int *)malloc(sizeof(int) * 2);
    *res[1] = 1 ;
    int *ali[2];
    int *hossain[2];
    hossain[0] = (int *)malloc(sizeof(int) *2);
    *hossain[0] = 1;
    *(hossain[0]+1) = 2;
    hossain[1] =(int *)malloc(sizeof(int) * 2);
    *hossain[1] = 1 ;
    *(hossain[1]+1) = 3;
    print_matric(hossain,2,2);
    ali[0] = (int *)malloc(sizeof(int) *2);
    *ali[0] = 1;
    *(ali[0]+1) = 2;
    ali[1] =(int *)malloc(sizeof(int) * 2);
    *ali[1] = 1 ;
    *(ali[1]+1) = 2;
    printf("\n");

    print_matric(ali,2,2);
    mat_mult(hossain,2,2,ali,2,2,res);
    printf("\n");
    print_matric(res,2,2);
    //print(make_cols(hossain,2,1),2);
    return 0 ;

}
void mat_add(int *mat1[],int mat1_rows,int mat1_cols,int *mat2[],int mat2_rows,int mat2_cols,int *mat_res[]){
    int i , j ;
    if (mat1_rows == mat2_rows && mat1_cols == mat2_cols){ // we can add two matric that have equal rows and column
            for(i = 0 ; i < mat1_rows ; i++)
                for (j = 0 ; j < mat1_cols;j++)
                    mat_res[i][j] = mat1[i][j] + mat2[i][j];
        return;
    }
    printf("enterly is wrong\n");
}
void mat_mult(int *mat1[],int mat1_rows,int mat1_cols, int *mat2[],int mat2_rows,int mat2_cols,int *mat_res[]){
    int i ,j;
    if (mat1_cols == mat2_rows){  // we cant mult two matric that column of matric 1 and rows matric 2
        for (i = 0 ; i < mat1_rows ; i++){    // dar zarb matric ma bayad satreh matric aval ro dar stoneh matric dovom zarb conim va hasel ro dar satreh o ston result gharar midahim
            for(j = 0 ; j < mat2_cols ; j++)   
                mat_res[i][j] = zarb(make_row(mat1,i,mat1_cols),make_cols(mat2,mat2_rows,j),mat2_rows);
        }
        return ;
    }
    printf("enterly is wrong\n");
}
int zarb(int *arr_first,int *arr_secend,int  size){// in tabeh result zarb satr va stone ro hesab miconinm
    int result = 0 ; 
    int i ;
    for(i = 0 ; i < size ; i++)
        result = result + *(arr_first+i) * (*(arr_secend+i));
    return result ;

}
int *make_row(int **mat1,int i , int mat1_cols){ // in tabeh yek matric 1 dar mat1_cols dorost miconad keh yek satr az matric ghabli mahsob myshavad
    int *p = (int *)malloc(sizeof(int) * mat1_cols);
    int j ;
    for (j = 0 ; j < mat1_cols;j++)
            *(p+j) = mat1[i][j]; 
    return p;
}
int *make_cols(int **mat2,int mat2_rows,int j){ // in tabeh yek matric 1 dar mat2_rows dorost miconad keh yek soton az matric ghabli mohsob myshavad 
    int *p = (int *)malloc(sizeof(int) * mat2_rows); 
    int i;
    for( i = 0 ; i < mat2_rows ; i++)
        *(p+i) = mat2[i][j];
    return p;
}
void mat_transpose(int *mat[],int mat_rows,int mat_cols,int *mat_res[]){ // dar in tabeh yek matric k dar n ro tabdil be yek matric n dar k miconim allbate

        int i , j ;
        for (i = 0 ; i < mat_rows ; i++)
                for(j = 0 ; j < mat_cols ; j++ )
                        mat_res[j][i] = mat[i][j]; // jayeh index ha ro avaz miconad

}
void print_matric(int *mat[],int row ,int col){
    int i,j;
    for (i = 0 ; i < row ; i++){
        printf("\n");
        for (j = 0 ; j < col ;j++)
            printf("%d ",mat[i][j]);
    }

}
void print(int *p , int size){
    int i = 0 ;
    for ( i = 0 ; i < size ; i++)
        printf("%d ",*(p+i));
}
