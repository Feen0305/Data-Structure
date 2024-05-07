//Phoorin Chinphuad 66070501043
//Circular table
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void InsertLastNode(struct node **start, int val);
int DeleteNodeByStep(struct node **start, int step);
void display(struct node *start);

int main(){
    int size, val, step;
    scanf(" %d %d", &size, &step);

    struct node *CirLL = NULL;

    for(int i = 0; i<size; i++){
        scanf(" %d", &val);
        InsertLastNode(&CirLL, val);
    }

    if(CirLL == NULL){
        printf("none\n");
    }
    else{
        printf("%d\n", DeleteNodeByStep(&CirLL, step));
    }
        

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

int DeleteNodeByStep(struct node **start, int step){
    struct node *ptr , *Preptr, *temp;
    int count = 0;

    if(*start == NULL){
        return 0;
    }

    ptr = *start;
    Preptr = NULL;
    while(ptr != ptr->next){
        count++;
        

        if(count % step == 0){
            Preptr->next = ptr->next;
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        else{
            Preptr = ptr;
            ptr = ptr->next;
        }
    }
    
    return ptr->data;
}