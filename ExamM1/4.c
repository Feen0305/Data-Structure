//Phoorin Chinphuad 66070501043

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

void enqueue(struct node **start);
void dequeue(struct node **start);
void peek(struct node **start);
void display(struct node **start);

int main(){
    int n;
    scanf("%d", &n);
    
    int INPUT[n];

    for(int i= 0; i<n ;i++){
        scanf("%d", &INPUT[i]);
    }

    // for(int i=0 ; i<3; i++){
    //     enqueue()
    // }
    // display(s);

    // printf("%c\n", peek(s));

    // for(int i=0; i<2; i++){
    //     pop(&s);
    // }
    // display(s);
    // while(!IsEmpty(s)){
    //     pop(&s);
    // }
    
}

int minSum(int input[], int size){
    struct node *pq;
    int num1, num2;

    for(int i = 0; i < size; i++){
        enqueue(&pq , input[i]);
    }
}


void enqueue(struct node **start , int input){
    int val, pri;
    struct node *ptr, *p;
    ptr = (struct node*)malloc(sizeof(struct node));
    scanf("%d %d", &val, &pri);

    ptr->data = input;
    ptr->priority = pri;
    
    if(*start == NULL || pri < (*start)->priority){
        ptr->next = *start;
        *start = ptr;
    }
    else{
        p = *start;
        while(p->next != NULL && p->next->priority <= pri){
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    
    return;
}

void dequeue(struct node **start){
    struct node *ptr;
    if(*start == NULL){
        return;
    }
    else{
        ptr = *start;
        *start = (*start)->next;
        free(ptr);
    }

    return;
}

void peek(struct node **start){
    return (*start)->data;
}

void display(struct node **start){
    struct node *ptr;
    ptr = *start;
    if(*start == NULL){
        printf("EMPTY QUEUE");
    }
    else{
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}