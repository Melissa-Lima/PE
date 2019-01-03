#include <stdio.h>

int Fibonacci(int n){
	if (n<2){
		return 1;
	}
	
	return Fibonacci(n-1)+Fibonacci(n-2);
}

int maiorFibonacci(int n){
	int fibo;
	int i=0;
	while (1){
		fibo=Fibonacci(i);
		if (fibo>=n){
			break;
			
		}
		i++;
	}
	return fibo;
}

int main(){

	int n=maiorFibonacci(5);
	printf("%d\n",n);
	return 0;
}
