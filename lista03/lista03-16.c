#include <stdio.h>

int euclides (int m, int n){
	if (n==1){
		return 1;
	}
	
	if (m%n==0){
		return n;
	}
	if (n%m==0){
		return m;
	}
	
	return euclides(n,m%n);
}

int main(){
	int mdc=euclides(50,6);
	printf("%d\n",mdc);
	return 0;
}
