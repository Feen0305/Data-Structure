//Phoorin Chinphuad 66070501043
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

struct Stack{
    char data[MAX];
    int TOP;
};

void push(struct Stack *s , char input);
char pop(struct Stack *s);
char peek(struct Stack s);
int IsEmpty(struct Stack s);
void display(struct Stack s);
char* shortenString(struct Stack *s, char input[]);

int main(){
    struct Stack s;
    s.TOP = -1;

    char INPUT[11] , *OUTPUT;
    scanf(" %s", INPUT);

    if(strlen(INPUT) > 10){
        printf("String Overflow!");
        return 0;
    }

    for(int i=0 ; i<3; i++){
        push(&s, INPUT[i]);
    }
    display(s);

    printf("%c\n", peek(s));

    for(int i=0; i<2; i++){
        pop(&s);
    }
    display(s);
    while(!IsEmpty(s)){
        pop(&s);
    }

    OUTPUT = shortenString(&s, INPUT);
    printf("%s", OUTPUT);

    return 0;
}

void push(struct Stack *s , char input){
    if(s->TOP == MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    else{
        s->data[++(s->TOP)] = input;
    }
    return;
}

char pop(struct Stack *s){
    if(IsEmpty(*s)){
        printf("Empty String\n");
        exit(0);
    }
    else{
        return s->data[(s->TOP)--];
    }
}

char peek(struct Stack s){
    if(IsEmpty(s)){
        printf("Empty String\n");
        exit(0);
    }
    else{
        return s.data[(s.TOP)];
    }
}

int IsEmpty(struct Stack s){
    return s.TOP == -1;
}

char* shortenString(struct Stack *s, char input[]){
    char output[11];
    for(int i=0 ; i<strlen(input); i++){
        if(IsEmpty(*s) || input[i] != peek(*s)){
            push(s, input[i]);
        }
        else{
            pop(s);
        }
    }

    if(IsEmpty(*s)){
        return "Empty String";
    }
    else{
        display(*s);
        //ส่งไปปริ้นนอก main ไม่ทันครับ
        // printf("%d\n",s->TOP);
        // output[(s->TOP)+1] = '\0';
        // while(!IsEmpty(*s)){
        //     printf("%d\n",s->TOP);
        //     output[(s->TOP)--] = pop(s);
        // }
    }

}

void display(struct Stack s){
    if(IsEmpty(s)){
        printf("Empty String\n");
        return;
    }
    else{
        for(int i=0; i<(s.TOP)+1; i++){
            printf("%c ", s.data[i]);
        }
        printf("\n");
    }
    
    return;
}



