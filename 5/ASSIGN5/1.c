//Phoorin Chinphuad 66070501043
//Assignment 6.1 : Sum Tree

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int IsSumTree(int tree[], int root, int size);

int main(){
    int tree[MAX];
    int data, index = 0;

    while(1){
        scanf(" %d", &data);
        if(data == -1001){ break; }
        tree[index++] = data;
    }
    
    if(IsSumTree(tree, 0 , index)){ printf("True\n"); }
    else{ printf("False\n"); }

    return 0;
}

int IsSumTree(int tree[], int root, int size){

    //root have no children
    if(((2*root+1) >= size) && ((2*root+2) >= size)){
        return tree[root];
    }
    else{

        //root have 1 child
        if((2*root + 2) >= size){
            int leftSum = IsSumTree(tree, 2 * root + 1, size);
            // printf("At root = %d data = %d leftsum = %d\n", root, tree[root], leftSum);
            if(tree[root] == leftSum){
                return tree[root]*2;
            }
            else{
                return 0;
            }
        }

        //root have 2 children
        else{
            int leftSum = IsSumTree(tree, 2 * root + 1, size);
            int rightSum = IsSumTree(tree, 2 * root + 2, size);
            // printf("At root = %d data = %d totalsum = %d\n", root, tree[root], leftSum + rightSum);
            if(tree[root] == leftSum + rightSum){
                return tree[root]*2;
            }
            else{
                return 0;
            }
        }
    }
}

