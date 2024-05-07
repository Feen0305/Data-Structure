//Phoorin Chinphuad 66070501043
//Ten to X

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void ConvertBASE(struct node **start, int num, int base);
void display(struct node *top);
void freeLL(struct node **top);

int main(){
    int num, base;
    scanf(" %d %d", &num, &base);

    struct node *LL = NULL;

    if(base < 2 || base > 36){ printf("invalid\n"); }
    else{
        while(num != 0){
            ConvertBASE(&LL ,num, base); 
            num /= base;
        }
        display(LL);
    }

    freeLL(&LL);
    return 0;
}

void ConvertBASE(struct node **top, int num, int base){
    struct node ptr;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num%base;
    
    if(*top == NULL){
        newnode->next = NULL;
        *top = newnode;
    }
    else{
        newnode->next = *top;
        *top = newnode;
    }
}

void display(struct node *top){
    struct node *ptr;
    char ALP[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(ptr == NULL){
        return;
    }

    while(ptr != NULL){
        if(ptr->data >= 10){
            printf("%c", ALP[ptr->data-10]);
            // -10 becuase it start to turn number into alphabet when number is 10 or upper
        }
        else{
            printf("%d", ptr->data);
        }
        ptr = ptr->next;
    }
}

void freeLL(struct node **top){
    struct node *ptr, *ptrNext;
    ptr = *top;
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