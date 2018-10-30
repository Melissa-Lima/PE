#include <stdio.h>

double potencia(double a, int b){
	double resultado = 1;
	int i;
	for (i=0; i<b; i++){
		resultado*=a;
	}
	
	return resultado;
}

int main(){
	
	int i;
	int base = 2;
	double pot;
	for (base=2; base<=10; base++){
		for (i=0; i<=10; i++){
			pot=potencia(base,i);
			printf("%.f\n",pot);
		}
	}
	return 0;
	
}
