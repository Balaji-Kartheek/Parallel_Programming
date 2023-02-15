#include<stdio.h>
#include<math.h>

int reverse_num(int num){
    int rev = 0;
    while(num){
        rev = rev*10 + num%10;
        num /= 10;
    }
    return rev;
}

int main(){
	
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);

	int i;
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	
	int reverse[n];
	

	printf("elements of the array: ");
	
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
		reverse[i] = reverse_num(arr[i]);
	}
	
	// reversed array 
	printf("\nReversed Array: \n");
	for(i=0;i<n;i++){
		printf("%d ",reverse[i]);
	}
	
	return 0;
}
