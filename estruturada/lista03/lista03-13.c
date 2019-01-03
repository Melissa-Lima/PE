#include <stdio.h>

int distintos(int n, int k){
	if (k==1){
		return n;
	}
	if (k==n){
		return 1;
	}
	
	return distintos(n-1,k-1) + distintos(n-1,k);
}

int main(){
	int distinto=distintos(7,4);
	printf("%d\n",distinto);
	return 0;
}
