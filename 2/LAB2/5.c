//Phoorin Chinphuad 66070501043
//Circular Linked List
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void InsertLastNode(struct node **start, int val);
void DeleteValueNode(struct node **start, int val);
void display(struct node *start);
void freeLL(struct node *start);

int main(){
    int val;
    char mode;

    struct node *CirLL = NULL;

    while(1){
        scanf(" %c", &mode);
        if(mode == 'E'){
            break;
        }
        else if(mode == 'I'){
            scanf(" %d", &val);
            InsertLastNode(&CirLL, val);
        }
        else if(mode == 'D'){
            scanf(" %d", &val);
            DeleteValueNode(&CirLL, val);
        }
        else{
            return 0;
        }
    }
    
    display(CirLL);
    freeLL(CirLL);

    return 0;
}

void InsertLastNode(struct node **start, int val){
    struct node *ptr;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if(*start == NULL){
        *start = newnode;
        newnode->next = *start;
        return;
    }
    ptr = *start;
    while(ptr->next != *start){
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->next = *start;
}

void DeleteValueNode(struct node **start, int val){
    struct node *ptr , *Preptr, *temp;

    if(*start == NULL){
        return;
    }

    ptr = *start;
    Preptr = NULL;
    while(ptr->data != val){
        Preptr = ptr;
        ptr = ptr->next;
        if(ptr == *start){
            return;
        }
    }

    // only one node deleted
    if(ptr->next == *start && Preptr == NULL){
        free(ptr);
        *start = NULL;
        return;
    }

    // first node deleted
    if(Preptr == NULL){
        ptr = *start;
        while (ptr->next != *start){
            ptr = ptr->next;
        }
        ptr->next = (*start)->next;
        ptr = *start;
        *start = (*start)->next;
        free(ptr);
        return;
    }

    // other node deleted
    Preptr->next = ptr->next;
    free(ptr);
    return;
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;

    
    if(ptr == NULL){
        printf("Empty\n");
        return;
    }

    do{
        printf("%d ", ptr->data);
        // printf("%p %p\n", ptr, ptr->next);
        ptr = ptr->next;
    }
    while(ptr != start);

    return;
}

// free allocated memories
void freeLL(struct node *start){
    struct node *ptr, *ptrNext;
    ptr = start;

    if(ptr == NULL){
        return;
    }

    do{
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }
    while(ptr != start);

    return;
}