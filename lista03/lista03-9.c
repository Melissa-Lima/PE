#include <stdio.h>

int multIter(int a, int b){
	int i;
	int soma=0;
	for (i=0; i<b; i++){
		soma=soma+a;
	}
	return soma;
}

int main(){

	int mult = multIter(6,3);
	printf("%d\n",mult);
	return 0;
}
