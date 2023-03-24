#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    
    int n;
    
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	
    #pragma omp parallel 
    {
        #pragma omp master
		{
			for(int i=1;i<=n;i++){
				sum = sum +i;
			}
		}
        
    }
    printf("Sum of %d numbers: %d\n", n,sum);
    return 0;
}
