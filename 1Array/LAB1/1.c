//Phoorin Chinphuad 66070501043
#include <stdio.h>
#include <stdlib.h>

int main(){
    int length;
    scanf(" %d", &length);

    int *arr = malloc( length * sizeof(int));
    for(int i=0; i<length; i++){
        scanf(" %d", arr+i);
    }

    int mode;
    scanf(" %d", &mode);
    if(mode == 1 && length<=1){
        printf("none");
    }
    else{
        for(int i=mode; i<length; i+=2){
            printf("%d ", *(arr+i));
        }
    }

    free(arr);
    return 0;
}