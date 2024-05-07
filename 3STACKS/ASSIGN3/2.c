//Phoorin Chinphuad 66070501043
//Palindrome checker

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

struct Stack{
    char data[MAX];
    int TOP;
};

bool IsPalindrome(char input[]);
void push(struct Stack *str, char input);

int main(){
    char INPUT[MAX];
    scanf(" %s", INPUT);

    if(IsPalindrome(INPUT)){ printf("yes\n"); }
    else{ printf("no\n"); }
    
    return 0;
}

bool IsPalindrome(char input[]){
    struct Stack String;
    String.TOP = -1;
    int length = strlen(input);

    for(int i=0; i<length; i++){
        push(&String, input[i]);
    }

    for(int i=0; i<length; i++){
        if(input[i] != String.data[String.TOP]){
            return false;
        }
        String.TOP--;
    }
    return true;
}

void push(struct Stack *str, char input){
    if(str->TOP == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        str->TOP++;
        str->data[str->TOP] = input;
    }

    return;
}