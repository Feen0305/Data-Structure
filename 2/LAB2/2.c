//Phoorin Chinphuad 66070501043
//Before or After Insertion ?

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void InsertNodeAfter(struct node **start , int length);
void InsertNodeBefore(struct node **start , int length);
void InsertNodeEnd(struct node **start, int val);
void display(struct node *start);
void freeLL(struct node *start);

int main(){
    int length , val;
    char mode;
    
    scanf(" %d", &length);
    struct node *LL = NULL;

    for(int i=0; i<length; i++){
        scanf(" %d", &val);
        InsertNodeEnd(&LL , val);
    }

    while(1){
        scanf(" %c", &mode);
        if(mode == 'E'){
            break;
        }
        else if(mode == 'A'){
            InsertNodeAfter(&LL , length);
        }
        else if(mode == 'B'){
            InsertNodeBefore(&LL , length);
            
        }
        else{
            printf("Invalid");
            freeLL(LL);
            return 0;
        }
    }

    display(LL);
    freeLL(LL);

    return 0;
}

void InsertNodeAfter(struct node **start , int length){
    struct node *ptr , *prePtr;
    int REFnumber, INSERTnumber, count = 0;
    scanf(" %d %d", &REFnumber, &INSERTnumber);

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = INSERTnumber;

    ptr = *start;
    prePtr = ptr;
    while(prePtr->data != REFnumber){
        // printf("%p:%d , count = %d\n",prePtr, prePtr->data, count);
        if (ptr == NULL){
            return;
        }
        prePtr = ptr;
        ptr = ptr->next;
        count++;
    }

    if(!count){
        newNode->next = prePtr->next;
        prePtr->next = newNode;
        return;
    }

    prePtr->next = newNode;
    newNode->next = ptr;
}

void InsertNodeBefore(struct node **start , int length){
    struct node *ptr , *prePtr;
    int REFnumber, INSERTnumber, count = 0;
    scanf(" %d %d", &REFnumber, &INSERTnumber);

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = INSERTnumber;

    ptr = *start;
    prePtr = ptr;
    while(ptr->data != REFnumber){
        prePtr = ptr;
        ptr = ptr->next;
        count++;
        if (ptr == NULL){
            return;
        }
    }

    if(!count){
        newNode->next = *start;
        *start = newNode;
        return;
    }
    
    prePtr->next = newNode;
    newNode->next = ptr;
}


void InsertNodeEnd(struct node **start, int val){
    struct node *ptr;

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
    return;
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
    return;
}

// free allocated memories
void freeLL(struct node *start){
    struct node *ptr, *ptrNext;
    ptr = start;

    while(ptr != NULL){
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }

    return;
}