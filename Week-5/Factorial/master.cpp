#include <omp.h>
#include <stdio.h>

int main() {
    int fact = 1;
    
    int n;
    
	printf("Enter the Number: \n");
	scanf("%d",&n);
	
    #pragma omp parallel 
    {
        #pragma omp master
		{
			for(int i=1;i<=n;i++){
				fact = fact *i;
			}
		}
        
    }
    printf("fact of %d numbers: %d\n", n,fact);
    return 0;
}
