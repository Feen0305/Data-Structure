//Phoorin Chinphuad 66070501043
//Stack as linked list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top , int val);
int pop(struct node **top);
int top(struct node *top);
int isEmpty(struct node *TOP);
void freeLL(struct node *TOP);

int main(){
    int val;
    char mode;
    struct node *StackLL = NULL;

    while(1){
        scanf(" %c", &mode);
        if(mode == 'p'){
            scanf(" %d", &val);
            push(&StackLL , val);
        }
        else if (mode == 'o'){
            if(isEmpty(StackLL)){
                printf("empty\n");
            }
            else{
                printf("%d\n", pop(&StackLL));
            }
        }
        else if (mode == 't'){
            if(isEmpty(StackLL)){
                printf("empty\n");
            }
            else{
                printf("%d\n", top(StackLL));
            }
        }
        else if (mode == 'e'){
            printf("%d\n", isEmpty(StackLL));
        }
        else if (mode == 'q'){
            break;
        }
        else{
            printf("Invalid choice.\n");
        }
    }
    freeLL(StackLL);
    return 0;
}

void push(struct node **top , int val){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = val;
    if(isEmpty(*top)){
        newnode->next = NULL;
        *top = newnode;
    }
    else{
        newnode->next = *top;
        *top = newnode;
    }
}

int pop(struct node **top){
    struct node *ptr;
    int tmp_data;

    if(isEmpty(*top)){
        return 0;
    }
    else{
        ptr = *top;
        *top = (*top)->next;
        tmp_data = ptr->data;
        free(ptr);
        return tmp_data;
    }
}

int top(struct node *top){
    if(isEmpty(top)){
        return 0;
    }
    else{
        return top->data;
    }
}

int isEmpty(struct node *TOP){
    if(TOP == NULL){return 1;}
    else{return 0;}
}

void freeLL(struct node *TOP){
    struct node *ptr, *ptrNext;
    ptr = TOP;
    if(ptr == NULL){
        return;
    }
    while(ptr != NULL){
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }
    return;
}