#include <stdio.h>

 void trocaIndice(int vetor[], int tamanho, int i, int j){
 	int guardaJ=vetor[j];
 	int guardaI=vetor[i];
 	vetor[i]=guardaJ;
 	vetor[j]=guardaI;
 }
 
 void inverte(int vetor[], int tamanho){
 	int i;
 	int j=tamanho-1;
 	for (i=0; i<tamanho/2; i++,j--){
 		trocaIndice(vetor,tamanho,i,j);
 	}
 }
 
 int main(){

	int i;
	int vetor[] = {1,2,3,4,5,6,7,8,9,10};
	int tamanho=10;
	inverte(vetor,tamanho);
	for (i=0; i<tamanho; i++){
		printf("%d\n",vetor[i]);
	}
 	return 0;
 }
