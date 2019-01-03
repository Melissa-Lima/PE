#include <stdio.h>
#define TAM_MAX 1003

void copiaVetor(int num1[], int num2[]){
  int k;
  for(k=0;k<TAM_MAX;k++){
    num2[k]=0;
  }
  for(k=0;k<TAM_MAX;k++){
    num2[k]=num1[k];
  }
}

void printaVetor(int num1[], int tamanho1){
	int i;
	for(i=0; i<tamanho1; i++){
		printf("%d",num1[i]);
	}
	printf("\n");
}

void multpor10(int num[],int quantidade){
  int i;
  for(i=1;i<TAM_MAX;i++){
    if(num[i]!=0){
      break;
    }
  }
  for(; i<TAM_MAX; i++){
    num[i-quantidade]=num[i];
    num[i]=0;
  }
}

void criaNumeraoDaString(char str[], int num[TAM_MAX], int tamanho){
	int i,finalString,caso;
	for(i=0; i<TAM_MAX; i++){
		num[i]=0;
	}
	if(str[0]=='-'){
		num[0]=1;
		caso=1;
	}else{
		tamanho-=1;
		caso=2;
	}
	if(caso==1){
		for(i=TAM_MAX-1, finalString=tamanho; finalString>0; i--,finalString--){
			num[i]=str[finalString]-'0';
		}
	}else{
		for(i=TAM_MAX-1, finalString=tamanho; finalString>=0; i--,finalString--){
			num[i]=str[finalString]-'0';
		}
	}
}

int contaDigitosStr(char str[]){
	int cont=0;
	int i;
	for (i=0; str[i]!='\n' && str[i]!='\0'; i++){
		if(str[i]!='-')
			cont++;
	}
	return cont;
}

void zeraVetor(int num[],int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		num[i]=0;
	}
}

void soma(int num1[], int num2[], int tamanho1, int tamanho2){
	int copia[TAM_MAX];
	int i,j;

	for(i=0; i<TAM_MAX; i++){
		copia[i]=num1[i];
	}

	for (j=TAM_MAX-1; j>TAM_MAX-tamanho1-2 && j>0; j--){
		if(copia[j]+num2[j]<10){
			num1[j]=copia[j]+num2[j];
		}else{
			copia[j-1]=copia[j-1]+((copia[j]+num2[j])/10);
			num1[j]=(copia[j]+num2[j])%10;
		}
	}
}

void multiplicacaoSimples(int num[], int multiplicador){
	int i,j,copia[TAM_MAX],vaium=0;

	if(multiplicador==0){
		zeraVetor(num,TAM_MAX);
        return;
	}

	for(i=0; i<TAM_MAX; i++){
		copia[i]=num[i];
	}

	for(j=TAM_MAX-1; j>=0; j--){
		if((multiplicador*copia[j])+vaium<10){
			num[j]=copia[j]*multiplicador+vaium;
			vaium=0;
		}else{
			num[j]=(copia[j]*multiplicador+vaium)%10;
			vaium=((copia[j]*multiplicador+vaium)/10);
		}
	}
}

void multiplicacao(int num1[], int num2[], int tamanho1, int tamanho2){
    int i, resultado[TAM_MAX], aux[TAM_MAX], somaresultado[TAM_MAX];
    int tamanhoSoma=tamanho1,dez=0;
    zeraVetor(somaresultado,TAM_MAX);
    for(i=TAM_MAX-1; i>=TAM_MAX-tamanho2; i--,tamanhoSoma++,dez++){
        copiaVetor(num1,aux);
        zeraVetor(resultado,TAM_MAX);
        multiplicacaoSimples(aux,num2[i]);
        copiaVetor(aux,resultado);
        printaVetor(aux,TAM_MAX);
        printf("i=%d, num2[i]=%d\n",i,num2[i]);
        if(i!=TAM_MAX-1){
            multpor10(resultado,dez);
        }
        soma(somaresultado,resultado,tamanhoSoma,tamanho1+1);
    }
    copiaVetor(somaresultado,num1);
}

void incrementaDividendo(int dividendo[], int qtdeDigito, int tamanhoDiv){
    int copia[TAM_MAX], inicioCop, inicioDiv,i;
    printaVetor(dividendo,TAM_MAX);
    copiaVetor(dividendo,copia);
    printaVetor(copia,TAM_MAX);
    zeraVetor(dividendo,TAM_MAX);
    printaVetor(dividendo,TAM_MAX);

    inicioCop=TAM_MAX-tamanhoDiv;
    inicioDiv=TAM_MAX-qtdeDigito;
    printf("inicioCop=%d inicioDiv%d\n",inicioCop,inicioDiv);

    for(i=0; i<qtdeDigito; i++,inicioDiv++,inicioCop++){
        dividendo[inicioDiv]=copia[inicioCop];
        printf("dividendo[inicioDiv]=%d, copia[inicioCop]=%d\n",dividendo[inicioDiv],copia[inicioCop]);
    }
}

int main(){
    char string1[TAM_MAX], string2[TAM_MAX];
	int tamanho1,tamanho2, vetor1[TAM_MAX], vetor2[TAM_MAX];

    fgets(string1,TAM_MAX+1,stdin);
	tamanho1=contaDigitosStr(string1);
	criaNumeraoDaString(string1,vetor1,tamanho1);
    /*fgets(string2,TAM_MAX+1,stdin);
	tamanho2=contaDigitosStr(string2);
	criaNumeraoDaString(string2,vetor2,tamanho2);*/

    incrementaDividendo(vetor1,4,tamanho1);
    printaVetor(vetor1,TAM_MAX);
    return 0;
}
