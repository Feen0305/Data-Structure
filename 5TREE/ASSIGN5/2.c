//Phoorin Chinphuad 66070501043
//Assignment 5.2: Prefix to Postfix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct Treenode{
    char data;
    struct Treenode *left, *right;
};

struct Treenode *add(struct Treenode *root, char data[], int *index);
struct Treenode *createnode(char data);
void post(struct Treenode* root);
int isOperand(char data);

int main(){
    struct Treenode *root = NULL;

    char input[MAX];
    int start_index = 0;
    scanf(" %s", input);

    root = add(root, input, &start_index);

    post(root);
    return 0;
}

struct Treenode *createnode(char data){
    struct Treenode *newNode = (struct Treenode*)malloc(sizeof(struct Treenode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Treenode *add(struct Treenode *root, char data[], int *index){
    if (data[*index] != '\0') {
        root = createnode(data[*index]);

        if (!isOperand(data[*index])) {
            (*index)++;
            root->left = add(root->left, data, index);
            (*index)++;
            root->right = add(root->right, data, index);
        }
    }

    return root;
}

// Postorder traversal: Left -> Right -> Root
void post(struct Treenode* root){
	if (root != NULL) {
        post(root->left);
        post(root->right);
        printf("%c", root->data);
        free(root);
	}
}

int isOperand(char data){
    return (data >= 'a' && data <= 'z') || 
        (data >= 'A' && data <= 'Z') ||
        (data >= '0' && data <= '9');
}
