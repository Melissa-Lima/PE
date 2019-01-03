#include <stdio.h>

float mediaLinha(int i, int c, int matriz[][1000]){
	int j;
	double media;
	int soma=0;
	for (j=0; j<c; j++){
		soma+=matriz[i][j];
	}
	
	media=(float)soma/c;
	return media;
}

float mediaColuna();


int main(){
	int i,j,l,c,numero;
	double media;
	int matriz[1000][1000];
	
	scanf("%d %d",&l,&c);

	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			scanf("%d",&numero);
			matriz[i][j]=numero;
		}	
	}
	
	media=mediaLinha(0,c,matriz);
	printf("%.2f\n",media);
	return 0;
}
