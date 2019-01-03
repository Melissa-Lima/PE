/*Melissa Lima - 11113815*/

#include <stdio.h>

void leEntrada(int tam, int sequencia[],int inverso){ /*esta funcao le a entrada do usuario*/
	char letra;
	int i, inicio, fim, passo;
	if (inverso){
		inicio=tam-1;
		fim=0;
		passo=-1;
	}else{
		inicio=0;
		fim=tam-1;
		passo=1;
	}
	for (i=inicio; (((!inverso) && (i<=fim)) || (inverso && (i>=fim))); i+=passo){
		do{
			scanf("%c",&letra);
		} while ((letra!='A')||(letra!='U' && letra!='C' && letra!='G'));
		if (letra == 'A'){
			sequencia[i]=1;
		} else if(letra=='U'){
			sequencia[i]=-1;
		} else if(letra=='C'){
			sequencia[i]=2;
		} else if(letra=='G'){
			sequencia[i]=-2;
		}
	}
}

int main(){
	int i, cont, achou;
	int tfrase, tpalavra;
	int frase[100];
	int palavra[25];

	scanf("%d",&tfrase);
	scanf("%d",&tpalavra);

	leEntrada(tfrase,frase,0);
	leEntrada(tpalavra,frase,1);
	i=0;
	achou=0;
	while(i<(tfrase-tpalavra)){
		cont=0;
		while(cont<tpalavra && (frase[i+cont]+=palavra[cont]==0)){
			cont++;
		}
		if (cont==tpalavra){
			printf("Silenciado em %d\n",i+1);
			break;
		}

		i++;
	}

	if (!achou){
		printf("Nao silenciado\n");
	}

	return 0;

}
