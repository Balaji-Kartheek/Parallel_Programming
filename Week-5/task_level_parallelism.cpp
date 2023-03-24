#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include <time.h>
#include<math.h>


/*
#pragma omp task directive is used to indicate that each task can be executed in parallel. 
The #pragma omp single directive ensures that the tasks are only launched once, 
and the #pragma omp parallel directive creates a team of threads to execute the tasks in parallel.
*/

#define SIZE 4 

int main() {
	
	int A[4] = { 1, 2, 3, 4 };
	int B[4] = { 5, 6, 7, 8 };
	int C[4];
	
	clock_t start, end; 
	double t_seq,t_par;
	
	start = clock();
	
	for (int i = 0; i < 4; i++) {
		C[i] = A[i] + B[i];
		printf("%d + %d = %d \n", A[i], B[i], C[i]);
	}
	
	for (int i = 0; i < 4; i++) {
		C[i] = A[i] - B[i];
		printf("%d - %d = %d \n", A[i], B[i], C[i]);
	}
	
	for (int i = 0; i < 4; i++) {
		C[i] = A[i] * B[i];
		printf("%d * %d = %d \n", A[i], B[i], C[i]);
	}
	
	end = clock();
	
	t_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	
	printf("OpenMp TaskLevel Parallesim\n");
	
	start = clock();
	
	#pragma omp parallel
	{
		#pragma omp single
		{
			#pragma omp task
			{
				for (int i = 0; i < 4; i++) {
					C[i] = A[i] + B[i];
					printf("%d + %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
				}
			}
			#pragma omp task
			{
				for (int i = 0; i < 4; i++) {
					C[i] = A[i] - B[i];
					printf("%d - %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
				}
			}
			#pragma omp task
			{
				for (int i = 0; i < 4; i++) {
					C[i] = A[i] * B[i];
					printf("%d * %d = %d (thread %d)\n", A[i], B[i], C[i], omp_get_thread_num());
				}
			}
		}
	}
	
	end = clock();
	
	t_par = ((double)(end - start)) / CLOCKS_PER_SEC;
	
	
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

