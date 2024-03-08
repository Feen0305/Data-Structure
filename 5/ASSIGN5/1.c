//Phoorin Chinphuad 66070501043
//Assignment 5.1 : Sum Tree

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int Sum(int tree[], int root, int size);
int IsSumTree(int tree[], int size);

int main(){
    int tree[MAX];
    int data, index = 0;

    while(1){
        scanf(" %d", &data);
        if(data == -1001){ break; }
        tree[index++] = data;
    }
    
    if(IsSumTree(tree, index)){ printf("True\n"); }
    else{ printf("False\n"); }

    return 0;
}

int Sum(int tree[], int root, int size){
    if(root >= size){
        return 0;
    }
    return Sum(tree, 2*root + 1, size) + tree[root] + Sum(tree, 2*root + 2, size);
}

int IsSumTree(int tree[], int size){
    if(size == 0 || size == 1){
        return 1;
    }

    int AllSum = Sum(tree, 0, size);

    if(AllSum/2 == tree[0]){ return 1;}
    else{ return 0; }
}