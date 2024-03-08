//Phoorin Chinphuad 66070501043

#include <stdio.h>

int main(){
    int size;
    scanf(" %d", &size);

    int arr[size];
    for(int i=0; i<size; i++){
        scanf(" %d", &arr[i]);
    }

    int start, end, step;
    scanf(" %d %d %d", &start, &end, &step);

    // set negative index to positive index
    if(start < 0){
        start = start + size;
    }	
    if(end < 0){
        end = end + size;
    }

    // for a oversize case
    if(start < end){
        if(start > size || start < 0){
            start = 0;
        }
        if(end > size || end < 0){
            end = size;
        }
    }
    else if (start > end)
    {
        if(start > size){
            start = size - 1;
        }
        if(end > size){
            end = 0;
        }
    }
    
    
    /*---------------------------------------------------------*/

    int check=0; //for checking that its have an element or not.

    // decrease or increase
    if(step>=0){
        for(int i=start; i<end; i+=step){
            printf("%d ", arr[i]);
            check = 1;
        }
    }
    else{
        for(int i=start; i>end; i+=step){
            printf("%d ", arr[i]);
            check = 1;
        }
    }

    //Do not have element to print out
    if(!check){
        printf("empty");
    }
    
    return 0;
}