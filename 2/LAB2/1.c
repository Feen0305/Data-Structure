//Phoorin Chinphuad 66070501043
//Linked Lists Insertion
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void InsertNodeBegin(struct node **start);
void InsertNodeEnd(struct node **start);
void display(struct node *start);

int main(){
    int length, mode;
    
    scanf(" %d", &length);
    scanf(" %d", &mode);

    struct node *LL = NULL;

    for(int i = 0; i<length; i++){
        if(mode == 1){
            InsertNodeBegin(&LL);
        }
        else if (mode == 2){
            InsertNodeEnd(&LL);
        }
        else{
            printf("Invalid");
            return 0;
        }
    }

    display(LL);

    // free allocated memories
    struct node *ptr, *ptrNext;
    ptr = LL;

    while(ptr != NULL){
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }

    return 0;
}

void InsertNodeBegin(struct node **start){
    int val;

    scanf(" %d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *start;
    
    *start = newNode;
}

void InsertNodeEnd(struct node **start){
    struct node *ptr;
    int val;

    scanf(" %d", &val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
    // printf("%p\n" ,*start);
    ptr = *start;

    if (*start == NULL) {
        *start = newNode;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;

    if(ptr == NULL){
        printf("Invalid");
    }

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

}
