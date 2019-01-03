 /* * * * * * * * * * * * * * * * * * * * * * * * 
*												 *
* 	             Melissa Lima					 *
*	              RA:11113815					 *
*												 *
* * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#define TAM_MAX 2003

/* Conta digitos da string que recebe como parametro sem incluir o sinal */
int contaDigitosStr(char str[]);

/* dado uma string e um vetor de inteiro e o tamanho da string, esse vetor copia todos os elementos da string para o final do vetor de inteiros num[TAM_MAX]. Ex: '12345' -> [0000012345] */
void criaNumeraoDaString(char string[], int num[TAM_MAX], int tamanho);

/* esta funcao zera todos elementos de um vetor recebdio como parametro*/
void zeraVetor(int num[],int tamanho);

/* conta os digitos de um vetor sem contar os primeiros 0 (da esquerda pra direita) e retorna a quantidade desses digitos, exemplo [00000123450] -> 6 */
int tamanhoVetor(int num[], int tamanho);

/* dado um vetor de inteiros, essa funcao imprime este vetor. */
void imprimeNumerao(int num1[], int tamanho);

/* dado dois vetores, determina se o primeiro é maior, menor ou igual ao segundo (em módulo) */
int maiorMenor(int num1[], int num2[], int tamanho1,int tamanho2);

/* dado dois vetores de inteiros, essa funcao faz a soma desses dois vetores como se fosse soma no papel. O valor da soma sera armazenado no num1[]*/
void soma(int num1[], int num2[],int tamanho1,int tamanho2);

/* dado dois vetores de inteiros, essa funcao faz a subtracao desses dois vetores como se fosse subtracao no papel. O valor da subtracao sera armazenado no num1[]*/
void subtrai(int num1[], int num2[], int tamanho1, int tamanho2);

/* dado um vetor e um inteiro, essa funcao multiplica cada digito do vetor pelo multiplcador (recebido no parametro). Ex: num[]=[1,2,3], multiplicador=2, após a chamada da funcao com num e multiplicador, o vetor num fica [2,4,6]*/
void multiplicacaoSimples(int num[], int multiplicador);

/*dado dois vetores e seus respectivos tamanho, esta funcao multiplica um vetor pelo outro (como se fosse no papel) e armazena o valor da multiplicacao em num1 */
void multiplicacao(int num1[], int num2[], int tamanho1, int tamanho2);

/* dado dois vetores, esta funcao transforma num2 em num1, ou seja, todas posicoes de num2 eh igual as respectivas posicoes de num1*/
void copiaVetor(int num1[], int num2[]);

/* dado um vetor como parametro esta funcao faz shift left de um vetor quantidade vezes.*/
void multpor10(int num[],int quantidade);

/********************************************************************************************************************************************************************************************************************************/

int contaDigitosStr(char str[]){
	int cont=0;
	int i;
	for (i=0; str[i]!='\n' && str[i]!='\0'; i++){
		if(str[i]!='-')
			cont++;
	}
	return cont;
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

void zeraVetor(int num[],int tamanho){
	int i;
	for(i=0; i<tamanho; i++){
		num[i]=0;
	}
}

int tamanhoVetor(int num[],int tamanho){
	int i,tamanhofinal;
	tamanhofinal=tamanho+1;
	if(tamanho==0){
		return 0;
	}
	for(i=TAM_MAX-tamanhofinal; i<TAM_MAX; i++){
		if(num[i]!=0){
			break;
		}
	}
	tamanho=TAM_MAX-i;
	if(tamanho==TAM_MAX){
		tamanho=0;
	}
	return tamanho;
}

void imprimeNumerao(int num[],int tamanho){
	int i;
	int tamanhototal=tamanhoVetor(num,tamanho);
	if(tamanhototal==0){
		printf("0");
	}
	if(num[0]==1 && tamanhototal!=0){
		printf("-");
	}
	if(tamanhototal!=0){
			for(i=TAM_MAX-tamanhototal; i<TAM_MAX; i++){
				printf("%d",num[i]);
			}
	}
	printf("\n");
}

int maiorMenor(int num1[], int num2[], int tamanho1, int tamanho2){
	int resultado=0,i;

	if(tamanho1>tamanho2){
		resultado=1;
	}else if(tamanho1<tamanho2){
		resultado=-1;
	}else{
		for(i=TAM_MAX-tamanho1; i<TAM_MAX; i++){
			if(num1[i]>num2[i]){
				resultado=1;
				break;
			}else if(num1[i]<num2[i]){
				resultado=-1;
				break;
			}
		}
	}
	return resultado;
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

void subtrai(int num1[], int num2[], int tamanho1, int tamanho2){
	int copia[TAM_MAX];
	int i,j;

	for(i=0; i<TAM_MAX; i++){
		copia[i]=num1[i];
	}
	for(j=TAM_MAX-1; j>TAM_MAX-tamanho1-2 && j>0; j--){
		if(copia[j]>=num2[j]){
			num1[j]=copia[j]-num2[j];
		}else{
			copia[j-1]=copia[j-1]-1;
			num1[j]=(copia[j]+10)-num2[j];
			num1[j-1]=num1[j-1]-1;
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

	for(j=TAM_MAX-1; j>0; j--){
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
    int tamanhoSoma=tamanho1,dez=0,sinal;
	if(num1[0]==num2[0]){
		sinal=0;
	}else{
		sinal=1;
	}
    zeraVetor(somaresultado,TAM_MAX);
    for(i=TAM_MAX-1; i>=TAM_MAX-tamanho2; i--,tamanhoSoma++,dez++){
        copiaVetor(num1,aux);;
        zeraVetor(resultado,TAM_MAX);
        multiplicacaoSimples(aux,num2[i]);
        copiaVetor(aux,resultado);
        if(i!=TAM_MAX-1){
            multpor10(resultado,dez);
        }
        soma(somaresultado,resultado,tamanhoSoma,tamanho1+1);
    }
    copiaVetor(somaresultado,num1);
	num1[0]=sinal;
}

void copiaVetor(int num1[], int num2[]){
  int k;
  for(k=0;k<TAM_MAX;k++){
    num2[k]=0;
  }
  for(k=0;k<TAM_MAX;k++){
    num2[k]=num1[k];
  }
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

int main(){
    int vetor1[TAM_MAX], vetor2[TAM_MAX],*maior,*menor;
	char string1[TAM_MAX], string2[TAM_MAX],operacao[3];
	int tamanho1,tamanho2,tamanhoMaior,tamanhoMenor,comparacao;

    string1[0]='0';
    string2[0]='0';

    while(1){
        fgets(string1,TAM_MAX+1,stdin);
		if(string1[0]=='F'){
			break;
		}
        fgets(string2,TAM_MAX+1,stdin);
		fgets(operacao,3,stdin);

		tamanho1=contaDigitosStr(string1);
		criaNumeraoDaString(string1,vetor1,tamanho1);


        tamanho2=contaDigitosStr(string2);
		criaNumeraoDaString(string2,vetor2,tamanho2);

        comparacao=maiorMenor(vetor1,vetor2,tamanho1,tamanho2);

        if(comparacao<1){
            maior=vetor2;
            menor=vetor1;
            tamanhoMaior=tamanho2;
            tamanhoMenor=tamanho1;
        }else{
            maior=vetor1;
            menor=vetor2;
            tamanhoMaior=tamanho1;
            tamanhoMenor=tamanho2;
        }
        switch(operacao[0]){
            case('+'):
                if(maior[0]==1 && menor[0]==1){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==1 && menor[0]==0){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                    maior[0]=1;
                }else if(maior[0]==0 && menor[0]==1){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==0 && menor[0]==0){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                }
                imprimeNumerao(maior,tamanhoMaior);
                break;

            case('-'):
                if(maior[0]==1 && menor[0]==1){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==1 && menor[0]==0){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
					maior[0]=0;
                }else if(maior[0]==0 && menor[0]==1){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                    if(maior==vetor2){
                        maior[0]=1;
                    }else{
                        maior[0]=0;
                    }
                }else if(maior[0]==0 && menor[0]==0){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                    if(menor==vetor1){
                        maior[0]=1;
                    }
                }
                imprimeNumerao(maior,tamanhoMaior);
                break;

			case('*'):
				multiplicacao(maior,menor,tamanhoMaior,tamanhoMenor);
				imprimeNumerao(maior,tamanhoMaior*2+1);
				break;
            }
    }

    return 0;
}
