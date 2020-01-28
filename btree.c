#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data_in;
    int lest_data;
    int bigest_data;
    int rapidly_lest_data;
    int rapidly_biggest_data;
    struct tree* left;
    struct tree* right;
    struct tree* mid;
};
int depth(struct tree *root);
void find (struct tree * temp , int array[],int *size);
struct tree* new_val(int a);
struct tree* insert(struct tree* root , int a);
void printbtree(struct tree * root);
struct tree * search(struct tree* root ,int a);
struct tree * dellet_ostad(struct tree* root ,int a);
int main(){
    struct tree* temp = NULL;
    struct tree* temp2 = NULL;
    temp = insert(temp,3);
    temp = insert(temp ,6);
    temp = insert(temp ,1);
    temp = insert(temp,5);
    temp = insert(temp,10);
    temp = insert(temp , 8);
    temp = insert(temp ,4);
    temp = insert(temp ,2);
    int depth_1= depth(temp);
    printf("%d\n",depth_1);
    temp = dellet_ostad(temp,10);
    printbtree(temp);
    temp2 = search(temp,5);
    printf("\n");
    printbtree(temp2);

    return 0 ;
}
struct tree* insert(struct tree* root , int a){
    int temp ;
    if (root == NULL){
        struct tree* new_value = new_val(a);
        return new_value;
    }
    else if (root -> data_in == 1 && a > root ->lest_data){
        root -> data_in = 2;
        root ->bigest_data = a;
    }
    else if (root -> data_in == 1 && a == root ->lest_data){
        root -> rapidly_lest_data += 1;
    }
    else if (root -> data_in == 1 && a < root -> lest_data){
        temp = root -> lest_data;
        root -> lest_data = a ;
        root -> bigest_data = temp;
        root ->data_in = 2 ;
    }
    else if (root -> data_in == 2 && a == root -> lest_data){
        root ->rapidly_lest_data +=1;
    }
    else if (root -> data_in == 2 && a == root -> bigest_data){
        root -> rapidly_biggest_data += 1;
    }
    else if (a < root ->lest_data && root -> data_in == 2){
        root -> left = insert(root -> left ,a);
    }
    else if(root -> data_in == 2 && a > root -> lest_data &&  a < root ->bigest_data){
        root -> mid = insert(root -> mid ,a);
    }
    else if (root -> data_in == 2 && root -> bigest_data  < a){
        root -> right = insert(root -> right,a);
    }
    return root ;
}
struct tree* new_val(int a){
    struct tree* root = (struct tree*)malloc(sizeof(struct tree));
    root -> data_in = 1;
    root ->lest_data = a;
    root ->rapidly_lest_data = 1;
    root ->left = NULL;
    root ->right = NULL;
    root -> mid = NULL;
    return root;
}
void printbtree(struct tree * root){
    if (root == NULL)
        return;
    printbtree(root -> left);
    printf("%d ",root ->lest_data);
    printbtree(root -> mid);
    if (root -> data_in == 2)
        printf("%d ",root ->bigest_data);
    printbtree(root -> right);
}
struct tree * search(struct tree* root ,int a){
    struct tree *new_val = (struct tree*)malloc(sizeof(struct tree));
    if (root == NULL)
        return new_val;
    else if (root -> data_in == 1){
        if ( a > root -> lest_data)
            return new_val;
        else if (a == root -> lest_data)
             new_val = root;
        else if (a < root -> lest_data)
            new_val = search(root -> left ,a);

    }
    else if (root -> data_in == 2){
        if ( a < root -> lest_data )
            new_val = search(root -> left ,a);
        else if (a == root -> lest_data)
            new_val = root ;
        else if (a < root -> bigest_data && a > root -> lest_data)
            new_val = search(root -> mid ,a);
        else if ( a == root -> bigest_data)
            new_val = root;
        else if ( a > root -> bigest_data)
            new_val = search(root -> right ,a);
    }
    return new_val;

}
struct tree * dellet_ostad(struct tree* root ,int a){
    struct tree * temp = NULL;
    int array[1000],i,size;
    size = 0 ;
    if (root == NULL)
        return NULL;
    else{

        find (root , array,&size);
        for (i = 0 ; i < size ; i++)
            if (array[i] != a)
               temp = insert(temp ,array[i]);
        return temp ;
    }

}
void find(struct tree * root , int array[],int *size){

    if (root == NULL)
            return;
    else {
        if (root->data_in == 1){
            array[*size] = root->lest_data;
            *size += 1;
            return;
        }
        else{
            find(root->left,array,size);
            array[*size] = root ->lest_data;
            *size += 1;
            find(root->mid,array,size);
            array[*size] = root ->bigest_data;
            *size += 1;
            find (root ->right ,array,size);
        }
    }
}
int depth(struct tree *root){
    int max ;
    if (root == NULL)
        return 0 ;

    int depth_left = 1 + depth(root-> left);
    int depth_mid = 1 + depth(root -> mid );
    int depth_right = 1 + depth(root -> right);
    if (depth_left >= depth_right)
        max = depth_left;
    else{
        max = depth_right;
        }
    if (max < depth_mid)
        max = depth_mid;
    return max;
}
