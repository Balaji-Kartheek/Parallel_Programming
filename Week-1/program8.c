#include<stdio.h>
#include<string.h>


int main(){

    int A[10][10];
    int D[10][10];
    int B[10][10];
    
    int m, n;

    printf("Enter the size of the matrix (rows, columns): ");
    scanf("%d%d", &m, &n);

    
    printf("Enter the elements of the matrix: \n");
    
    int i,j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        scanf("%d", &A[i][j]);
        }
    }

    printf("The  matrix is: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        printf("%d ", A[i][j]);
        }
    printf("\n");
    }

    for(i =0;i<m;i++){
        for(j=0;j<n;j++){

            if(i!=0 && i!=m-1 && j!=0 && j!=m-1){
                int num = A[i][j];
                
                
            }else{
                B[i][j] = A[i][j];
                
            }
        }
    }

    


    return 0;
}