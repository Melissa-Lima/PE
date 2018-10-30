#include <stdio.h>

int potencia(double a, int b){
	double resultado = 1;
	int i;
	for (i=0; i<b; i++){
		resultado*=a;
	}
	
	return resultado;
}

int main(){

	double a = 2;
	int b = 1;	
	double pot = potencia(a,b);
	printf("potencia = %.1f\n", pot); 
	return 0;
}
