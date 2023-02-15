#include<stdio.h>

int main(){
	
	int a,b;
	char op;
	
	printf("Enter the first number A: \n");
	scanf("%d",&a);
	
	printf("Enter the second number B: \n");
	scanf("%d",&b);
	
	printf("Enter the operation (+, -, *, /): \n");
	scanf(" %c",&op);
	
	switch(op){
		case '+':
			printf("A +B = %d", a+ b);
			break;
		case '-':
			printf("A -B = %d", a-b);
			break;
		case '*':
			printf("A *B = %d", a*b);
			break;
		case '/':
			if(b == 0){
				printf("Exception: Zero doesn't divides");
			}else{
				printf("A / B = %d", a/b);
			}
			break;
		default:
			printf("Invalid operation");
	}
	
	return 0;
}
