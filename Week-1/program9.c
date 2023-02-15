#include<stdio.h>
#include<string.h>


int main(){

    char A[10][10];
    int B[10][10];
    char STR[100];
    int m, n;

    printf("Enter the size of the matrix (rows, columns): ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the matrix: \n");
    int i, j;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        scanf(" %c", &A[i][j]);
        }
    }

    printf("The charactor matrix is: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        printf("%c ", A[i][j]);
        }
    printf("\n");
    }

    printf("Enter the elements of the matrix: \n");
    
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        scanf("%d", &B[i][j]);
        }
    }

    printf("The frequency matrix is: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
        printf("%d ", B[i][j]);
        }
    printf("\n");
    }

    int cnt,k=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cnt = B[i][j];
            while(cnt!=0){
                STR[k] = A[i][j];
                cnt--;
                k++;
            }
        }
    }

    STR[k] = '\0';

    printf("\n");
    for(int i=0;i<strlen(STR);i++){
        printf("%c",STR[i]);
    }

    printf("\n string STR : %s",STR);

    return 0;
}