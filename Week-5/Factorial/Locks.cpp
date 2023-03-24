#include <omp.h>
#include <stdio.h>

omp_lock_t A;

int main() {
    int fact = 1;
    
    int n;
    
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	
	omp_init_lock(&A);
	
    #pragma omp parallel shared(n,fact) 
    {
        #pragma omp for
        for (int i = 2; i <=n; i++) {
            
            omp_set_lock(&A);
            {
                fact= fact * i;
            }
            omp_unset_lock(&A);
        }
    }
    printf("fact of %d numbers: %d\n", n,fact);
    
    omp_destroy_lock(&A);
    
    return 0;
}
