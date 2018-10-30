#include <stdio.h>

void reguaInglesa(int n){
	int i;
	
	if (n==0){
		printf("\n");
	}
	
	if(n!=0){
		reguaInglesa(n-1);
	
		for (i=1; i<=n; i++){
			printf("-");
		}
		
		printf("\n");
		
		reguaInglesa(n-1);
	}
}

int main(){
	reguaInglesa(10);
	return 0;
}
