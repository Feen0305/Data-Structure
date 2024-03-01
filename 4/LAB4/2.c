//Phoorin Chinphuad 66070501043
//Lab 5.2 : เมื่อไหร่จะถึงคิวฉันบ้าง???

#include <stdio.h>

int front = -1 , rear = -1;

void insert(int q[] , int size);
void del(int q[] , int size);
void show(int q[] , int size);
int IsEmpty(int q[]);
int IsFull(int q[], int size);

int main(){

    int size;
    scanf(" %d", &size);

    int Queue[size];
    
    char mode;
    while(1)
    {
        scanf(" %c", &mode);
        if(mode == 'I'){ insert(Queue , size); }
        else if(mode == 'D'){ del(Queue, size); }
        else if(mode == 'S'){ show(Queue, size); }
        else if(mode == 'E'){ break; }
        else
        { 
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}

void insert(int q[] , int size){

    int val;
    scanf(" %d", &val);

    if(IsFull(q, size))
    {
        printf("Queue is full!!\n");
        return ;
    }
    else if(IsEmpty(q))
    {
        front = rear = 0;
        q[rear] = val;
    }
    else if(rear == size-1 && front != 0)
    {
        rear = 0;
        q[rear] = val;
    }
    else{
        q[++rear] = val;
    }

    return ;
}

void del(int q[], int size){

    int val;
    if(IsEmpty(q))
    {
        printf("Queue is empty!!\n");
        return ;
    }
    printf("%d\n",q[front]);
    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if(front == size -1){ front = 0; }
        else{ front++; }
    }

    return ;
}

void show(int q[], int size){

    if(IsEmpty(q))
    {
        printf("Queue is empty!!\n");
        return ;
    }
    else
    {
        printf("Front: %d\n", front);
        printf("Items: ");
        if(front < rear)
        {
            for(int i=front; i<=rear; i++){ printf("%d ", q[i]); }
        }
        else if(front > rear)
        {
            for(int i=front; i<=size-1; i++){ printf("%d ", q[i]); }
            for(int i=0; i<=rear; i++){ printf("%d ", q[i]); }
        }
        else
        {
            printf("%d ", q[rear]);
        }
        printf("\n");
        printf("Rear: %d\n", rear);
    }
    return ;
}

int IsEmpty(int q[]){
    return front == -1 && rear == -1;
}

int IsFull(int q[], int size){
    return (front == 0 && rear == size-1) || (front == rear+1);
}