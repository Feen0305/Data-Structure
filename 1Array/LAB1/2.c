//Phoorin Chinphuad 66070501043
#include <stdio.h>
#include <stdlib.h>

void smallest_number(int *arr , int length);
void largest_number(int *arr , int length);
void print(int number, int position);

int main(){
    int length;
    scanf(" %d", &length);

    int *arr = malloc( length * sizeof(int) );
    for(int i=0; i<length; i++){
        scanf(" %d", arr+i);
    }
    largest_number(arr, length);
    smallest_number(arr, length);

    free(arr);
    return 0;
}

void smallest_number(int *arr , int length){
    int pos=0;
    for(int i=0; i<length; i++){
        if(*(arr+i) < *(arr+pos)){
            pos = i ;
        }
    }
    print(*(arr+pos) , pos);
}
    

void largest_number(int *arr , int length){
    int pos=0;
    for(int i=0; i<length; i++){
        if(*(arr+i) > *(arr+pos)){
            pos = i ;
        }
    }
    print(*(arr+pos) , pos);
}

void print(int number, int position){
    printf("%d %d\n", number, position);
}