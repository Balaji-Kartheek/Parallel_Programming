#include<stdio.h>
#include<string.h>
int main(){
	
	char str1[100];
	char str2[100];
	char result[200];
	
	printf("Enter the string1: \n");
	scanf("%s",str1);
	printf("Enter the string2: \n");
	scanf("%s",str2);
	
	
	printf("given string1 is: %s of length %d \n",str1,strlen(str1));
	printf("given string2 is: %s of length %d \n",str2,strlen(str2));
	
	int i,k=0;
	
	//given both strings are of same length
	int len = strlen(str1);
	
	for(i=0;i<len;i++){
		result[k] = str1[i];
		k++;
		result[k] = str2[i];
		k++;
	}
	
	result[k] = '\0';
	
	printf("Desired string is: %s\n",result);
	
	// printf("Result string is: \t");
	// for(i=0;i<(2*len);i++){
	// 	printf("%c",result[i]);
	// }
	
	
	
	
	return 0;
}
