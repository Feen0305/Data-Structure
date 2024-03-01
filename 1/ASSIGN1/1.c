//Phoorin Chinphuad 66070501043
//Jump Game
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VAL 2147483647
int minJump = INITIAL_VAL;

void Jump_ways(int position, int count, int array[], int length);

int main(){
    int length;
    scanf(" %d", &length);
    
    int ARR[length];
    for(int i =0; i<length; i++){
        scanf(" %d", &ARR[i]);
    }

    Jump_ways(0, 0, ARR, length);
    if (minJump == INITIAL_VAL){
        printf("Not Possible");
    }
    else{
        printf("%d", minJump);
    }
    return 0;
}

void Jump_ways(int position, int count, int array[], int length){
    if(position == length-1){
        if (count < minJump){
            minJump = count;
        }
    }
    else{
        for(int i=position+1 ; i<=position + array[position] && i<length; i++){
            Jump_ways(i, count+1, array, length);
        }
    }
}