//Phoorin Chinphuad 66070501043
//Symmetric Matrix
#include <stdio.h>

int symmetric(int rows, int cols, int matrix[rows][cols]);
int skew_symmetric(int rows, int cols, int matrix[rows][cols]);

int main(){
    int rows, cols;
    scanf(" %d %d", &rows, &cols);

    int matrix[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }

    if(symmetric(rows, cols, matrix)){
        printf("The matrix is symmetric");
    }
    else if(skew_symmetric(rows, cols, matrix))
    {
        printf("The matrix is skew-symmetric");
    }
    else{
        printf("None");
    }
    
    return 0;
}

int symmetric(int rows, int cols, int matrix[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != matrix[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

int skew_symmetric(int rows, int cols, int matrix[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != -1*(matrix[j][i])){
                return 0;
            }
        }
    }
    return 1;
}