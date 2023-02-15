#include<stdio.h>

int main(){
	
	char str[100];
	char result[100];
	
	printf("Enter the string: \n");
	scanf("%s",str);
	
	
	printf("given string is: %s of length %d \n",str,strlen(str));
	
	int i,j,k=0;
	int count = 0;
	for(i=0;i<strlen(str);i++){
		count++;
		for(j=0;j<count;j++){
			result[k] = str[i];
			k++;
		}
	}
	result[k] = '\0';
	printf("Desired string is : %s",result);
	
	
	
	return 0;
}
