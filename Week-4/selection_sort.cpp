#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>


//              selection sort

int main(){
	
	clock_t start, end;
	double t_seq,t_par;

	
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	
	int arr[n];
	int arr2[n];
	
	printf("Enter the Elements of the array: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Elements of the array: \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		arr2[i] = arr[i];
	}
	printf("\n");
	
	
	
	//   sequential program
	
	start = clock();
	
	for(int i=0;i<n-1;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min = j;
			}
			
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	
	end = clock();
	t_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	printf("Seqential program output: \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		
	}
	printf("\n");
	
	
	// original array
	for(int i=0;i<n;i++){
		arr[i] = arr2[i];
	}
	
	
	
	start = clock();
	


	int min = 0;
	#pragma omp parallel for shared(arr, n) private(min)
	for(int i = 0; i < n-1; i++){
	    min = i;
	    for(int j = i+1; j < n; j++){
	        if(arr[j] < arr[min]){
	            min = j;
	        }
	    }
	    int temp = arr[i];
	    arr[i] = arr[min];
	    arr[min] = temp;
	}
	
	
	end = clock();
	
	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	
	
	printf("Parallel program output: \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		
	}
	printf("\n");
	
	printf("Time taken for sequential execution:%f\n", t_seq);
	printf("Time taken for parallel execution:%f\n", t_par);
	
	double speed_up = 0;
	speed_up = (t_seq) / (t_par);
	printf("SpeedUp:%f\n", speed_up);
	
	double efficiency = 0;
	int num_threads = 8;
	efficiency = (speed_up) / (num_threads);
	printf("Efficiency:%f\n", efficiency);
	
	return 0;
}
