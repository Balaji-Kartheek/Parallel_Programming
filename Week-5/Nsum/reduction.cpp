#include <omp.h>
#include <stdio.h>

int main() {
    int sum = 0;
    
    int n;
    
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
    #pragma omp parallel  
    {
        #pragma omp for reduction(+:sum)
        for (int i = 1; i <=n; i++) {
        	{
                sum= sum + i;
                printf("Sum value is %d\n",sum);
            }
        }
    }
    printf("Sum of %d numbers: %d\n", n,sum);
    return 0;
}
