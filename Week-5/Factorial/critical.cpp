#include <omp.h>
#include <stdio.h>

int main() {
    int fact = 1;
    
    int n;
    
	printf("Enter the Number: \n");
	scanf("%d",&n);
    #pragma omp parallel shared(n,fact) 
    {
        #pragma omp for
        for (int i = 2; i <=n; i++) {
            #pragma omp critical
            {
                fact= fact * i;
            }
        }
    }
    printf("fact of %d numbers: %d\n", n,fact);
    return 0;
}
