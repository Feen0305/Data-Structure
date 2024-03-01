//Phoorin Chinphuad 66070501043
//It's Sorting Time

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int score;
    int ID;
    struct node *next;
};

void InsertLastNode(struct node **start, int score, int id);
void SortByID(struct node **start, int size);
void SortByScore(struct node **start, int size);
void display(struct node *start);

int main(){
    int size, score, id, mode;
    scanf(" %d", &size);

    struct node *LL = NULL;

    for(int i = 0; i<size; i++){
        scanf(" %d %d", &id, &score);
        InsertLastNode(&LL, score, id);
    }

    scanf(" %d", &mode);
    if(mode == 0){
        SortByID(&LL, size);
    }
    else{
        SortByScore(&LL, size);
    }

    display(LL);
    free(LL);
    return 0;
}

void InsertLastNode(struct node **start, int score, int id){
    struct node *ptr;

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->ID = id;
    newnode->score = score;
    newnode->next = NULL;
    
    ptr = *start;

    if (*start == NULL) {
        *start = newnode;
        return;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    return;
}

void SortByScore(struct node **start, int size){
    struct node *ptr;
    int tempScore , tempID;

    for (int i = 0; i < size - 1; i++) {
        ptr = *start;

        while (ptr->next != NULL) {
            if (ptr->score > ptr->next->score) {
                tempID = ptr->ID;
                tempScore = ptr->score;
                
                ptr->ID = ptr->next->ID;
                ptr->score = ptr->next->score;

                ptr->next->ID = tempID;
                ptr->next->score = tempScore;
            }
            ptr = ptr->next;
        }
    }

    return;
}
    

void SortByID(struct node **start, int size){
    struct node *ptr;
    int tempScore , tempID;

    for (int i = 0; i < size - 1; i++){
        ptr = *start;

        while (ptr->next != NULL) {
            if (ptr->ID > ptr->next->ID) {
                tempID = ptr->ID;
                tempScore = ptr->score;
                
                ptr->ID = ptr->next->ID;
                ptr->score = ptr->next->score;

                ptr->next->ID = tempID;
                ptr->next->score = tempScore;
            }
            ptr = ptr->next;
        }

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
        printf("%d ", ptr->score);
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
