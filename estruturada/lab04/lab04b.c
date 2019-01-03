/* Melissa Lima - 11113815*/

#include <stdio.h>

void converteR (int x,int b);

void converte(int x,int base){
	converteR(x,base);
	printf("\n");
}

void converteR(int x, int base){
		int digito;
		if (base>x){
			printf("%d",x);
		}else{
			digito = x%base;
			converteR(x/base,base);
			printf("%d",digito);
		}
	}

int main(){

	int x,base;
	
	scanf("%d%d", &x,&base);
	
	converte(x,base);
	
	return 0;
}
