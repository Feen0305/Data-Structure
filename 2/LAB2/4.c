//Phoorin Chinphuad 66070501043
//Linked list that can go back

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

void InsertNodeEnd(struct node **start, int val);
void DeleteValueNode(struct node **start, int val);
void SearchAroundNode(struct node **start, int val);
void display(struct node *start);
void freeLL(struct node *start);

int main(){
    int val;
    char mode[3];

    struct node *DByLL = NULL; // DByLL is Doubly Linked list

    while(1){
        scanf(" %s", mode);
        if(strcmp(mode, "END") == 0){
            break;
        }
        else if(strcmp(mode, "ADD") == 0){
            scanf(" %d", &val);
            InsertNodeEnd(&DByLL , val);
        }
        else if(strcmp(mode, "DEL") == 0){
            scanf(" %d", &val);
            DeleteValueNode(&DByLL , val);
        }
        else if(strcmp(mode, "SCH") == 0){
            scanf(" %d", &val);
            SearchAroundNode(&DByLL , val);
        }
        else{
            printf("Invalid");
            return 0;
        }
    }

    display(DByLL);
    freeLL(DByLL);

    return 0;
}

void InsertNodeEnd(struct node **start, int val){
    struct node *ptr;
    
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*start == NULL){
        *start = newnode;
        // printf("Node %p\n", (*start));
        // printf("Previous %p and Next %p !!\n",(*start)->prev, (*start)->next);
        return;
    }
    ptr = *start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    // printf("Node %p value> %d\n", ptr, ptr->data);
    // printf("Previous %p and Next %p !!\n", ptr->prev, ptr->next);
    
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
        *start = (*start)->next;
        (*start)->prev = NULL;
        // printf("Previous %p and Next %p !!\n", (*start)->prev, (*start)->next);
        return;
    }
    if(ptr->next == NULL){
        prePtr->next = NULL;
        free(ptr);
        return;
    }
    prePtr->next = ptr->next;
    ptr->next->prev = prePtr;
    free(ptr);
    return;
}

void SearchAroundNode(struct node **start, int val){
    struct node *ptr;
    if(*start == NULL){
        return;
    }
    
    ptr = *start;
    while(ptr->data != val){
        ptr = ptr->next;
        if(ptr == NULL){
            printf("none\n");
            return;
        }
    }

    if(ptr->prev != NULL || ptr->next != NULL){
        if(ptr->prev == NULL){
            printf("NULL ");
        }
        else if ((*ptr->prev).data)
        {
            printf("%d ", (*ptr->prev).data);
        }

        if(ptr->next == NULL){
            printf("NULL\n");
        }
        else if((*ptr->next).data){
            printf("%d\n", (*ptr->next).data);
        }

        return;
    }
    
    return;
}

void display(struct node *start){
    struct node *ptr, *Preptr;
    ptr = start;

    if(ptr == NULL){
        printf("none\nnone");
        return;
    }

    while(ptr != NULL){
        // printf("n>%p P>%p c>%p\n",ptr->next,ptr->prev, ptr);
        printf("%d ", ptr->data);
        // printf("Node %p value> %d\n", ptr, ptr->data);
        // printf("Previous %p and Next %p !!\n", ptr->prev, ptr->next);
        Preptr = ptr;
        ptr = ptr->next;
    }
    printf("\n");
    while(Preptr != NULL){
        printf("%d ", Preptr->data);
        // printf("Node %p value> %d\n", ptr, ptr->data);
        // printf("Previous %p and Next %p !!\n", ptr->prev, ptr->next);
        Preptr = Preptr->prev;
        
    }

    return;
}

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