//Phoorin Chinphuad 66070501043
//Infix to Postfix

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

struct Stack
{
    char data[MAX];
    int TOP;
};

void InfixToPostfix(char Infix[], char Postfix[]);
void push(struct Stack *operator , char infix);
char pop(struct Stack *operator);
int IsEmpty(struct Stack stack);
int isOperand(char oprd);
int ItsPrecudure(char optr);

int main(){
    char INPUT[MAX];
    char Postfix[MAX];
    scanf("%s", INPUT);

    InfixToPostfix(INPUT, Postfix);
    printf("%s", Postfix);

    return 0;
}

void InfixToPostfix(char Infix[], char Postfix[]){
    struct Stack operator;
    operator.TOP = -1;
    
    // i stands for index IF and PF stands for Infix Postfix.
    int iPF = 0;

    for(int iIF = 0; iIF < strlen(Infix); iIF++){
        char buff = Infix[iIF];

        // printf("%c\n", buff);

        if(isOperand(buff)){
            Postfix[iPF++] = buff;
        }
        else if(buff == '('){
            push(&operator, buff);
        }
        else if(buff == ')'){
            while(operator.data[operator.TOP] != '(' && !IsEmpty(operator)){
                Postfix[iPF++] = pop(&operator);
            }
            pop(&operator); //pop '('
        }
        else{
            while(ItsPrecudure(buff) <= ItsPrecudure(operator.data[operator.TOP]) && !IsEmpty(operator)){
                if(buff == '^' && operator.data[operator.TOP] == '^'){
                    break;
                }
                else{
                    Postfix[iPF++] = pop(&operator);
                }
            }
            push(&operator , buff);
            // printf("Operator push\n");
        }
    }

    while(!IsEmpty(operator)){
        Postfix[iPF++] = pop(&operator);
    }

    Postfix[iPF] = '\0';

    return;
}

void push(struct Stack *operator , char infix){
    if(operator->TOP == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        operator->data[++(operator->TOP)] = infix;
    }
    return;
}

char pop(struct Stack *operator){
    if(IsEmpty(*operator)){
        printf("Stack Empty\n");
        exit(0);
    }
    else{
        return operator->data[(operator->TOP)--];
    }
}

int IsEmpty(struct Stack stack){
    return stack.TOP == -1;
}

int isOperand(char oprd){
    return  (oprd >= 'A' && oprd <= 'Z') || 
            (oprd >= 'a' && oprd <= 'z') || 
            (oprd >= '0' && oprd <= '9');
}

int ItsPrecudure(char optr){
    //optr = operator
    if(optr == '^'){ return 3; }
    else if (optr == '*' || optr == '/'){ return 2; }
    else if (optr == '+' || optr == '-'){ return 1; }
    else{ return 0; }
}
