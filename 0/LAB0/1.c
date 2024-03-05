//Phoorin Chinphuad 66070501043
#include <stdio.h>

int main(){
    int length;
    scanf(" %d", &length);

    int number, elements[length];
    int count = 0;

    for(int i = 0; i<length; i++){
        int check = 0;
        scanf(" %d", &number);
        for(int j=0; j<count; j++){
            if(number==elements[j]){
                check = 1;
            }
        }
        if(check == 0){
            elements[count] = number;
            count += 1;
        }
    }

    printf("%d\n", count);
    for(int i = 0; i<count; i++){
            printf("%d ", elements[i]);
        }
    }
