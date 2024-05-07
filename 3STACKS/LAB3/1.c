//Phoorin Chinphuad 66070501043
//Stack Array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(int arr[], int val, int* TOP);
void pop(int arr[], int* TOP);
void show(int arr[], int TOP);
bool isFull(int SIZE, int TOP);
bool isEmpty(int TOP);

int main(){
    int size, mode, val, TOP = -1;
    scanf(" %d", &size);

    if(size <= 0){
        printf("Please enter a positive number.");
        return 0;
    }

    int *arr = (int*)malloc(sizeof(int)*size);
    
    while(1){
        scanf(" %d", &mode);
        if(mode == 1){ //Push
            scanf(" %d", &val);
            if(isFull(size, TOP)){
                printf("Stack Overflow.");
                break;
            }
            push(arr , val, &TOP);
        }
        else if (mode == 2){ //pop
            if(isEmpty(TOP)){
                printf("Stack Underflow.\n");
                break;
            }
            pop(arr, &TOP);
        }
        else if(mode == 3){ //show
            if(isEmpty(TOP)){
                printf("Stack is empty.\n");
                break;
            }
            show(arr, TOP);
            break;
        }
        else if(mode == 4){ // Exit
            printf("Exiting...\n");
            break;
        }
        else{
            printf("Invalid choice.\n");
            break;
        }
    }
    
    free(arr);
    return 0;
}

void push(int arr[], int val, int* TOP){
    (*TOP)++;
    arr[*TOP] = val;
    return;
}

void pop(int arr[], int* TOP){
    (*TOP)--;
    return;
}

void show(int arr[], int TOP){
    for(int i = TOP; i>-1; i--){
        printf("%d\n", arr[i]);
    }
    return;
}

bool isFull(int SIZE, int TOP){
    if(TOP == SIZE - 1){return true;}
    else{return false;}
}

bool isEmpty(int TOP){
    if(TOP == -1){return true;}
    else{return false;}
}