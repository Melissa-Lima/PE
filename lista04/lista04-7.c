#include <stdio.h>

int intersecao(int vetor1[], int vetor2[],int tamanho1,int tamanho2){
	int i,j;
	int quantidade=0;
	
	for (i=0; i<tamanho1; i++){
		for (j=0; j<tamanho2; j++){
			if (vetor1[i]==vetor2[j]){
				quantidade++;
			}
		}
	}
	
	return quantidade;
}

int main(){
	int vetor1[] = {1,2,3,4};
	int vetor2[] = {1,4,5,8,9};
	int inter=intersecao(vetor1,vetor2,4,5);
	printf("%d\n",inter);
	
	return 0;
}
