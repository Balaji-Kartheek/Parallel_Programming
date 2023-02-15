#include<stdio.h>

int main(){
	int A[10][10];
	int B[10][10];
	int n;
	
	printf("Enter the size of the matrix: \n");
	scanf("%d", &n);
	
	printf("Enter elements of the matrix: \n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Elements in the matrix A:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0; i<n; i++){
		int max=A[i][0], min=A[i][0];
		for(int j=0; j<n; j++){
			if(A[i][j] > max) max = A[i][j];
			if(A[i][j] < min) min = A[i][j];
		}
		
		for(int j=0; j<n; j++){
			if(i==j){
				B[i][j] = 0;
			}
			else if(i<j){
				B[i][j] = min;
			}
			else{
				B[i][j] = max;
			}
		}
	}
	
	printf("Elements in the matrix B:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", B[i][j]);	
		}
		printf("\n");
	}
	
	return 0;
}
