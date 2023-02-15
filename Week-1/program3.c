#include<stdio.h>
#include<string.h>
int main(){
	
	char str[100];
	
	printf("Enter the string: \n");
	scanf("%s",str);
	
	
	printf("given string is: %s of length %d \n",str,strlen(str));
	
	int i=0;
	for(i=0;i<strlen(str);i++){
		if(str[i]<=90 && str[i]>=65){
			
			str[i] = str[i] + 32;
			
		}
		
		else if(str[i]<=122 && str[i]>=97){
			
			str[i] = str[i] - 32;
			
		}
	}
	
	printf("After toggling the given string is: %s\n",str);
	
	
	
	
	return 0;
}
