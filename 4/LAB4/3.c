//Phoorin Chinphuad 66070501043
//Lab 5.3 : Secret Code Only You and I Know

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

struct node
{
    char data;
    int priority;
    struct node *next;
};

void enqueue(struct node **start , char input);
void display(struct node *start);
int GetPriorityOF(char in);
void freeQ(struct node **q);
int IsVowel(char in);
int IsAlphabet(char in);

int main(){
    struct node *queue = NULL;

    char input[MAX];
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0';

    for(int i = 0; i < strlen(input); i++)
    {
        enqueue(&queue , input[i]);
    }

    display(queue);
    freeQ(&queue);

    return 0;
}

void enqueue(struct node **start , char input){
    
    struct node *ptr;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = input;
    newnode->priority = GetPriorityOF(input);

    if(*start == NULL || newnode->priority > (*start)->priority)
    {
        newnode->next = *start;
        *start = newnode;
    }
    else
    {
        ptr = *start;
        while(ptr->next != NULL && ptr->next->priority >= newnode->priority)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode; 
    }
    
    return ;
}

void display(struct node *start){
    struct node *ptr;
    ptr = start;
    if(ptr == NULL)
    {
        printf("Queue is empty!!");
        return ;
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%c", ptr->data);
            ptr = ptr->next;
        }
    }
    
    return ;
}

int GetPriorityOF(char in){
    if(IsVowel(in)){ return 3; }
    else if(IsAlphabet(in)){ return 1; }
    else{ return 2; }
}

void freeQ(struct node **start){

    struct node *ptr , *temp;
    ptr = *start;
    if(ptr == NULL)
    {
        printf("Queue is empty!!");
        return ;
    }
    else
    {
        while(ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }

    *start = NULL;
    return ;
}

int IsVowel(char in){
    return in =='A' || in =='E' || in =='I' || in =='O' || in =='U'
        || in =='a' || in =='e' || in =='i' || in =='o' || in =='u';
}

int IsAlphabet(char in){
    return (in >= 'A' && in <= 'Z') || (in >= 'a' && in <= 'z');
}