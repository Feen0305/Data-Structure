//Phoorin Chinphuad 66070501043
//Kth Smallest Element in a BST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; 
    struct node *left, *right;
};

struct node *createnode(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){ return createnode(data); }

    if ( data < root->data ){ root->left = insert( root->left ,data); }
    else if (data >= root->data ){ root->right = insert( root->right , data); }

    return root;
    
}

void inorder(struct node *root, int *count, int k){
    if(root != NULL){
        inorder(root->left, count, k);
        (*count)++;
        if(*count == k){
            printf("%d", root->data);
        }
        inorder(root->right, count, k);
    }
    return;
}

void freeTree(struct node *root){
    if(root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
    return ;
}

void FindsmallestK(struct node *root, int size,  int k){
    int count = 0;
    if(k <= size && k > 0){
        inorder(root , &count , k);
    }
    else{
        printf("None");
    }
    freeTree(root);
}

int main(){
    struct node *root = NULL;

    int size, data , indexK;
    scanf(" %d", &size);

    for(int i = 0; i<size; i++){
        scanf(" %d", &data);
        root = insert(root ,data);
    }

    scanf(" %d", &indexK);
    FindsmallestK(root, size, indexK);
}