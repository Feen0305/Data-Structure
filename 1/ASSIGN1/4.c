//Phoorin Chinphuad 66070501043
//Matrix Multiplication
#include <stdio.h>

void input_arr(int rows, int columms, int matrix[rows][columms]);

int main(){
    int n_rows, n_columms;
    scanf(" %d %d", &n_rows, &n_columms);
    int matrix_n[n_rows][n_columms];
    input_arr(n_rows, n_columms, matrix_n);

    int m_rows, m_columms;
    scanf(" %d %d", &m_rows, &m_columms);
    int matrix_m[m_rows][m_columms];
    input_arr(m_rows, m_columms, matrix_m);

    int product_matrix[n_rows][m_columms];
    if(n_columms == m_rows){
        for(int i=0; i<n_rows; i++){
            for(int j=0; j<m_columms; j++){
                product_matrix[i][j] = 0;
                for(int k=0; k<n_columms && k<m_rows; k++){
                    product_matrix[i][j] += matrix_n[i][k] * matrix_m[k][j];
                }
            }
        }
    }
    else{
        printf("Not Compatible");
        return 0;
    }

    for(int i=0; i<n_rows; i++){
        for(int j=0; j<m_columms; j++){
            printf("%d ", product_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void input_arr(int rows, int columms, int matrix[rows][columms]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columms; j++){
            scanf(" %d", &matrix[i][j]);
        }
    }
}