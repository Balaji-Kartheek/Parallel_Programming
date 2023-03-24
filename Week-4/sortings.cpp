#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>


//              sorting

int main(){
	
	clock_t start, end;
	double t_seq,t_par;

	
	int n;
	printf("Enter the size of the array: \n");
	scanf("%d",&n);
	
	int arr[n];
	
	printf("Enter the Elements of the array: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	printf("Elements of the array: \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	//   sequential program
	
	start = clock();
	
	// 0 - n/2-1   --> insertion sort
	
	for(int i=1;i<n/2;i++){
		int j= i-1;
		int key = arr[i];
		while(key< arr[j] && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	
	
	// n/2 - n      ---> Quick sort
	
	for(int i=n/2;i<n;i++){
		
	}
	
	end = clock();
	t_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	
//	start = clock();
//	
//	int min =0;
//	#pragma omp parallel for collapse(2) shared(min)
//	for(int i=0;i<n-1;i++){	
//		min = i;	
//		for(int j=i+1;j<n;j++){
//			
//			if(arr[j]<arr[min]){
//				min = j;
//			}
//			
//			int temp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = temp;
//		}
//	}
//	
//	end = clock();
//	
//	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;
//	
//	
//	
	printf("Elements of the array: \n");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
//	
//	printf("Time taken for sequential execution:%f\n", t_seq);
//	printf("Time taken for parallel execution:%f\n", t_par);
//	
//	double speed_up = 0;
//	speed_up = (t_seq) / (t_par);
//	printf("SpeedUp:%f\n", speed_up);
//	
//	double efficiency = 0;
//	int num_threads = 8;
//	efficiency = (speed_up) / (num_threads);
//	printf("Efficiency:%f\n", efficiency);
	
	return 0;
}
