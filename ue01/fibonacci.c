#include<stdio.h>
 
int fibonacci(int n){
	if(n == 0){
		return 0;
	}
	
	else if(n == 1){
		return 1;
	}
	
	else return (fibonacci(n - 1) + fibonacci(n-2));	
	
}

int main(int argc, char *argv[]){
	
	int f;
	int i = 0;
	int c;
	
	scanf("%d", &f);
	
	for(c = 1; c <= f; c++){
		printf("%d\n", fibonacci(i));
		i++;
	}
	
	
	return 0;
}