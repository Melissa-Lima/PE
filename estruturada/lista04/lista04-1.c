 #include <stdio.h>
 
 void trocaIndice(int vetor[], int tamanho, int i, int j){
 	int guardaJ=vetor[j];
 	int guardaI=vetor[i];
 	vetor[i]=guardaJ;
 	vetor[j]=guardaI;
 }
 
 int main(){
 	int vetor[] = {1,2,3,4,5,6,7};
 	trocaIndice(vetor,7,2,3);
 	printf("%d\n%d\n",vetor[2],vetor[3]);
 	return 0;
 }
