/* * * * * * * * * * * * * * * * * * * * * * * * *
*												 *
* 	Melissa Lima								 *
*	RA:11113815									 *
*												 *
* * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#define TAM_MAX 1002

/* Conta digitos da string que recebe como parametro sem incluir o sinal */
int contaDigitosStr(char str[]);

/* recebe um vetor de inteiro e seu tamanho e manda seus digitos pro final, exemplo: [1234500000] -> [0000012345] */
void mandaProFinal(int tamanho, int num[]);

/* conta os digitos de um vetor sem contar os primeiros 0 (da esquerda pra direita) e retorna a quantidade desses digitos, exemplo [00000123450] -> 6 */
int tamanhoVetor(int num[]);

/* determina qual vetor eh maior e menor em modulo quando comparados entre si (num1[] e num2[]). Os vetores maior[] e menor[] serao o num1[] ou num2[]*/
int maiorMenor(int num1[], int num2[], int tamanho1, int tamanho2);

/* dado uma string e um vetor de inteiro e o tamanho da string, esse vetor copia todos os elementos da string para o vetor de inteiros num[TAM_MAX]*/
void criaNumeraoDaString(char string[], int num[TAM_MAX], int tamanho);

/* dado dois vetores de inteiros, essa funcao faz a soma desses dois vetores como se fosse soma no papel. O valor da soma sera armazenado no num1[]*/
void soma(int num1[], int num2[]);

/* dado dois vetores de inteiros, essa funcao faz a subtracao desses dois vetores como se fosse subtracao no papel. O valor da subtracao sera armazenado no num1[]*/
void subtrai(int num1[], int num2[]);

/* dado um vetor de inteiros, essa funcao imprime este vetor. */
void imprimeNumerao(int num1[]);

/* - -  - -  - -  - -  - -  - -  - -  - -  - -  - -  - -  - -  - -  */

int contaDigitosStr(char str[]){
	int cont=0;
	int i;
	for (i=0; str[i]!='\n' && str[i]!='\0'; i++){
		if(str[i]!='-')
			cont++;
	}
	if(cont==1 && str[0]=='0'){
		cont=0;
	}
	return cont;
}
void mandaProFinal(int tamanho, int num[]){
	int copia[TAM_MAX], i, k;
	for(i=0; i<TAM_MAX; i++){
		copia[i]=num[i];
	}
	for(i=1; i<TAM_MAX; i++){
		num[i]=0;
	}
	for(k=TAM_MAX-1, i=tamanho; i>=1; i--,k--){
		num[k]=copia[i];
	}
}

int tamanhoVetor(int num[]){
	int i,tamanho;
	for(i=1; i<TAM_MAX; i++){
		if(num[i]!=0){
			break;
		}
	}
	tamanho=TAM_MAX-i;
	if(tamanho==TAM_MAX){
		tamanho=0;
	}
	printf("%d",tamanho);
	printf("\n");
	return tamanho;
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

void criaNumeraoDaString(char string[], int num[TAM_MAX], int tamanho){
	int i,caso,comecoString;
	for(i=0; i<TAM_MAX; i++){
		num[i]=0;
	}
	if(string[0]=='-'){
		num[0]=1;
		comecoString=1;
		caso=1;
	}else if(string[0]!='0'){
		num[0]=0;
		comecoString=0;
		caso=2;
	}
	if(caso==1){
		for(i=1; comecoString<=tamanho; i++, comecoString++){
			num[i]=string[comecoString]-'0';
		}
	}else{
		for(i=1; comecoString<tamanho; i++, comecoString++){
			num[i]=string[comecoString]-'0';
		}
	}
}

void soma(int num1[], int num2[]){
	int copia[TAM_MAX];
	int i,j;
	for(i=0; i<TAM_MAX; i++){
		copia[i]=num1[i];
	}

	for (j=TAM_MAX-1; copia[j]!=0 || num2[j]!=0; j--){
		if(copia[j]+num2[j]<10){
			num1[j]=copia[j]+num2[j];
		}else{
			copia[j-1]=copia[j-1]+((copia[j]+num2[j])/10);
			num1[j]=(copia[j]+num2[j])%10;
			num1[j-1]=num1[j-1]+((num1[j]+num1[j])/10);
		}
	}
	for(i=0; i<TAM_MAX; i++){
		printf("%d",num1[i]);
	}
	printf("soma \n");
}

void subtrai(int num1[], int num2[]){
	int copia[TAM_MAX];
	int i,j;

	for(i=0; i<TAM_MAX; i++){
		copia[i]=num1[i];
	}
	for(j=TAM_MAX-1; copia[j]!=0 || num2[j]!=0; j--){
		if(copia[j]>=num2[j]){
			num1[j]=copia[j]-num2[j];
		}else{
			copia[j-1]=copia[j-1]-1;
			num1[j]=(copia[j]+10)-num2[j];
			num1[j-1]=num1[j-1]-1;
		}
	}
	for(i=0; i<TAM_MAX; i++){
		printf("%d",num1[i]);
	}
	printf("sub \n");
}

void imprimeNumerao(int num1[]){
	int i;
	int tamanho=tamanhoVetor(num1);
	if(tamanho==0){
		printf("entrei aqui1\n");
		printf("0");
	}
	if(num1[0]==1 && tamanho!=0){
		printf("-");
	}
	if(tamanho!=0){
		printf("entrei aqui3");
		for(i=1; i<TAM_MAX;i++){
			if(num1[i]!=0){
				break;
			}
		}
	}
	for(; i<TAM_MAX;i++){
		printf("%d",num1[]);
	}
	printf("\n");
}

int main(){
	int vetor1[TAM_MAX], vetor2[TAM_MAX];
	char string1[TAM_MAX], string2[TAM_MAX], operacao[2];
	int tamanho1,tamanho2,*maior,*menor;

	string1[0]='0';

	while(1){

		fgets(string1,TAM_MAX+1,stdin);
		if(string1[0]=='F'){
			break;
		}
		fgets(string2,TAM_MAX+1,stdin);
		fgets(operacao,3,stdin);

		tamanho1=contaDigitosStr(string1);
		criaNumeraoDaString(string1,vetor1,tamanho1);
		mandaProFinal(tamanho1,vetor1);

		tamanho2=contaDigitosStr(string2);
		criaNumeraoDaString(string2,vetor2,tamanho2);
		mandaProFinal(tamanho2,vetor2);
		if(maiorMenor(vetor1,vetor2,tamanho1,tamanho2)<0){
			maior=vetor2;
			menor=vetor1;
		}else{
			maior=vetor1;
			menor=vetor2;
		}
		switch(operacao[0]){
			case('+'):
				if(maior[0]==1 && menor[0]==1){
					soma(maior,menor);
				}else if(maior[0]==1 && menor[0]==0){
					subtrai(maior,menor);
					maior[0]=1;
				}else if(maior[0]==0 && menor[0]==1){
					subtrai(maior,menor);
				}else if(maior[0]==0 && menor[0]==0){
					soma(maior,menor);
					if(maior==vetor2){
						maior[0]=1;
					}
				}
				imprimeNumerao(maior);
				break;

			case('-'):
				if(maior[0]==1 && menor[0]==1){
					subtrai(maior,menor);
				}else if(maior[0]==1 && menor[0]==0){
					subtrai(maior,menor);
					maior[0]=0;
				}else if(maior[0]==0 && menor[0]==1){
					printf("entrei aqui sub\n");
					soma(maior,menor);
					maior[0]=0;
				}else if(maior[0]==0 && menor[0]==0){
					subtrai(maior,menor);

				}
				imprimeNumerao(maior);
				break;
			}
		}
	return 0;
}
