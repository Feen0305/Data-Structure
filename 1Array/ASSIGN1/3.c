//Phoorin Chinphuad 66070501043
//Spiral Array Printer
#include <stdio.h>

void spiral_printing(int ST_rows, int ST_cols, int rows, int cols, int matrix[rows][cols]);

int main(){
    int rows, cols, count=0;
    scanf(" %d %d", &rows, &cols);

    int matrix[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }

    int START_rows = 0 , START_cols = 0; 
    spiral_printing(START_rows, START_cols, rows, cols, matrix);

    return 0;
}

void spiral_printing(int ST_rows, int ST_cols, int rows, int cols, int matrix[rows][cols]){
    
    while(ST_rows < rows && ST_cols < cols){

        // printf("--------------------TO RIGHT-----------------\n");

        for(int i = ST_cols; i<cols; i++){
            printf("%d ", matrix[ST_rows][i]);
        }
        ST_rows++;

        // printf("------------------DOWn-----------------\n");

        for(int i = ST_rows; i< rows; i++){
            printf("%d ", matrix[i][cols-1]);
        }
        cols--;

        // printf("----------------LEFT-------------------\n");

        if(ST_cols < cols){
            for(int i = cols-1; i >= ST_cols; i--){
                printf("%d ", matrix[rows-1][i]);
            }
        }
        rows--;

        // printf("------------------UP--------------------\n");

        if(ST_rows < rows){
            for(int i = rows-1; i>= ST_rows; i--){
                printf("%d ", matrix[i][ST_cols]);
        }
        }
        ST_cols++;

        // printf("check point %d %d %d %d\n",ST_rows, ST_cols, rows, cols);
    }
}