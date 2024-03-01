//Phoorin Chinphuad 66070501043
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, rows, columms, primary_sum = 0, secondary_sum = 0;
    scanf("%d %d", &rows, &columms);
    if(rows != columms){
        printf("ERROR");
        return 0;
    }
    
// elements of matrix
    int matrix[rows][columms];
    for(i=0; i<rows; i++){
        for(j=0; j<columms; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }
//

// primary
    for(i=0; i<rows; i++){
        primary_sum += matrix[i][i];
        }
    printf("Primary: %d\n", primary_sum);
//

// secondary
    i = 0;
    while(i < rows){
        secondary_sum += matrix[i][columms-i-1];
        i++;
    }
    printf("Secondary: %d", secondary_sum);
//

    return 0;
}