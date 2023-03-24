#include <omp.h>
#include <stdio.h>

omp_lock_t A;

int main() {
    int sum = 0;
    
    int n;
    
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	
	omp_init_lock(&A);
	
    #pragma omp parallel shared(n,sum) 
    {
        #pragma omp for
        for (int i = 1; i <=n; i++) {
            
            omp_set_lock(&A);
            {
                sum= sum + i;
            }
            omp_unset_lock(&A);
        }
    }
    printf("Sum of %d numbers: %d\n", n,sum);
    
    omp_destroy_lock(&A);
    
    return 0;
}
