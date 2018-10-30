#include <stdio.h>

long fatorial(int n){
	if (n<=0){
		return 1;
	}
	
	return n*fatorial(n-1);
}

int main(){
	int fat=fatorial(5);
	printf("%d\n",fat);
	return 0;
}
