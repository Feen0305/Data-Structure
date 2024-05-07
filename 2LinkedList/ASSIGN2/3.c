//Phoorin Chinphuad 66070501043
//Reverse Linked List

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void InsertLastNode(struct node **start, int val);
void display(struct node *start);
void ReverseLL(struct node **start, int init, int last);

int main(){
    int val, INITindex, LASTindex;
    char str[3];

    struct node* LL = NULL;

    while(1){
        scanf(" %s", str);
        if(!strcmp(str,"END")){
            break;
        }
        val = atoi(str);
        InsertLastNode(&LL, val);
    }
    scanf(" %d %d", &INITindex, &LASTindex);
    ReverseLL(&LL, INITindex, LASTindex);
    
    display(LL);
    free(LL);
    return 0;
}

void InsertLastNode(struct node **start, int val){
    struct node *ptr;

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
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
    return;
}

void ReverseLL(struct node **start, int init, int last){
    struct node *ptr, *PrePtr, *nextnode, *tmp;

    ptr = *start;
    for(int i = 0; i<init-1; i++){
        PrePtr = ptr;
        ptr = ptr->next;
        if(ptr->next == NULL){
            ptr = *start;
            break;
        }
    }
    // printf("%d ", ptr->data);
    nextnode = ptr->next;
    // printf("%d\n", nextnode->data);

    for(int i=init; i<last; i++){
        tmp = nextnode->next;
        nextnode->next = ptr;
        ptr = nextnode;
        nextnode = tmp;
    }
    if(init == 1){
        (*start)->next = nextnode;
        // printf("%d\n", ptr->data);
        *start = ptr;
    } 
    else{
        PrePtr->next->next = nextnode;
        PrePtr->next = ptr;
    }

}

void display(struct node *start){
    struct node *ptr;
    ptr = start;

    if(ptr == NULL){
        printf("none");
    }

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return;
}

// free allocated memories
void freeLL(struct node *start){
    struct node *ptr, *ptrNext;
    ptr = start;

    do{
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }
    while(ptr != start);

    return;
}