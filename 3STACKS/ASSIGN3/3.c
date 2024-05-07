//Phoorin Chinphuad 66070501043
//Parenthesis Checker

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Stack{
    char data[MAX];
    int TOP;
};

int IsBalance(char input[]);
void push(struct Stack *open, char input);
void pop(struct Stack *open);
int IsEmpty(struct Stack arr);
int IsDual(char open, char close);

int main(){
    char INPUT[MAX];
    scanf(" %s", INPUT);

    if(IsBalance(INPUT)){ printf("The string is balanced\n"); }
    else{ printf("The string is not balanced\n"); }
    
    return 0;
}

int IsBalance(char input[]){
    struct Stack OpenBlk;
    OpenBlk.TOP = -1;
    int length = strlen(input);

    for(int i = 0; i<length; i++){
        if(input[i] == '[' || input[i] == '(' || input[i] == '{'){
            push(&OpenBlk, input[i]);
        }
        else if (input[i] == ']' || input[i] == ')' || input[i] == '}')
        {
            if(!IsDual(OpenBlk.data[OpenBlk.TOP],input[i]) || IsEmpty(OpenBlk)){
                return 0;
            }
            pop(&OpenBlk);
        }
    }

    return IsEmpty(OpenBlk);
}

void push(struct Stack *open, char input){
    if(open->TOP == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        open->TOP++;
        open->data[open->TOP] = input;
    }
    
    return;
}

void pop(struct Stack *open){
    if(open->TOP == -1){
        printf("Stack Empty\n");
    }
    else{
        open->TOP--;
    }

    return;
}

int IsEmpty(struct Stack arr){
    return arr.TOP == -1;
}

int IsDual(char open, char close){
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));

}

