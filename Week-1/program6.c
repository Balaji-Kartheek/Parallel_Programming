#include<stdio.h>

int main(){
    int m, n;
    printf("Enter the size of the matrix (m x n): \n");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    printf("Enter elements of the matrix: \n");

    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Elements in the matrix: \n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int vector_size;
    printf("Enter the size of the vector: \n");
    scanf("%d", &vector_size);

    if(n != vector_size){
        printf("Matrix-vector multiplication is not possible in this case.\n");
        return 0;
    }

    int vector[vector_size];
    printf("Enter elements of the vector: \n");
    for(i=0; i<vector_size; i++){
        scanf("%d", &vector[i]);
    }

    printf("Elements in the vector: \n");
    for(i=0; i<vector_size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");

    int product[m];
    for(i=0; i<m; i++){
        product[i] = 0;
        for(j=0; j<n; j++){
            product[i] += matrix[i][j] * vector[j];
        }
    }

    printf("Elements in the product: \n");
    for(i=0; i<m; i++){
        printf("%d ", product[i]);
    }
    printf("\n");

    return 0;
}
