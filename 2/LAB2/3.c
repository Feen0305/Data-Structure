//Phoorin Chinphuad 66070501043
//Where to DELETE ?

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void DeleteFirstNode(struct node **start);
void DeleteLastNode(struct node **start);
void DeleteValueNode(struct node **start, int val);
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
        else if(mode == 'F'){
            DeleteFirstNode(&LL);
        }
        else if(mode == 'L'){
            DeleteLastNode(&LL);
            
        }
        else if(mode == 'N'){
            scanf(" %d", &val);
            DeleteValueNode(&LL, val);
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

void DeleteFirstNode(struct node **start){
    struct node *ptr;

    if(*start == NULL){
        return;
    }
    ptr = *start;
    *start = (*start)->next;
    free(ptr);
    return;
}

void DeleteLastNode(struct node **start){
    struct node *ptr , *prePtr;
    int count = 0;

    if(*start == NULL){
        return;
    }
    ptr = *start;
    while(ptr->next != NULL){
        prePtr = ptr;
        ptr = ptr->next;
        count++;
    }

    if(!count){
        *start = NULL;
        free(ptr);
        return;
    }
    prePtr->next = NULL;
    free(ptr);
    return;
}

void DeleteValueNode(struct node **start, int val){
    struct node *ptr , *prePtr;
    int count = 0;

    if(*start == NULL){
        return;
    }
    ptr = *start;
    while(ptr->data != val){
        prePtr = ptr;
        ptr = ptr->next;
        if(ptr == NULL){
            return;
        }
        count++;
        // printf("%d " , prePtr->data);
    }
    if(!count){
        DeleteFirstNode(start);
        return;
    }
    prePtr->next = ptr->next;
    free(ptr);
    return;
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

    while(ptr != NULL){
        ptrNext = ptr->next;
        free(ptr);
        ptr = ptrNext;
    }

    return;
}
