#include <stdio.h>
#define TAM_MAX 1003
/*1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/

/*OK*/
int contaDigitosStr(char str[]){
	int cont=0;
	int i;
	for (i=0; str[i]!='\n' && str[i]!='\0'; i++){
		if(str[i]!='-')
			cont++;
	}
	return cont;
}

/*OK*/
void criaNumeraoDaString(char str[], int num[TAM_MAX], int tamanho){
	int i,caso,comecoString;
	for(i=0; i<TAM_MAX; i++){
		num[i]=0;
	}
	if(str[0]=='-'){
		num[0]=1;
		caso=1;
	}else{
		caso=2;
	}
	if(caso==1){
		for(i=1, comecoString=1; comecoString<=tamanho; comecoString++,i++){
			num[i]=str[comecoString]-'0';
			/*printf("i = %d, comecoString = %d, str[comecoString] = %c, num[i]=%d\n",i,comecoString,str[comecoString],num[i]);*/
		}
	}else{
		for(i=1, comecoString=0; comecoString<tamanho; comecoString++,i++){
			num[i]=str[comecoString]-'0';
			/*printf("i = %d, comecoString = %d, str[comecoString] = %c, num[i]=%d\n",i,comecoString,str[comecoString],num[i]);*/
		}
	}
}

/*OK*/
void mandaProFinal(int tamanho, int num[]){
	int copia[TAM_MAX], i,final,inicial;
	if(tamanho!=0){
		for(i=0; i<TAM_MAX; i++){
			copia[i]=num[i];
		}
		for(i=1; i<TAM_MAX; i++){
			num[i]=0;
		}
		for(final=TAM_MAX-1, inicial=tamanho; inicial<=tamanho && inicial>0; final--, inicial--){
			num[final]=copia[inicial];
		}
	}
}

/*OK*/
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
	return tamanho;
}

/*OK*/
void imprimeNumerao(int num[]){
	int i;
	int tamanho=tamanhoVetor(num);
	if(tamanho==0){
		printf("0");
	}
	if(num[0]==1 && tamanho!=0){
		printf("-");
	}
	if(tamanho!=0){
			for(i=TAM_MAX-tamanho; i<TAM_MAX; i++){
				printf("%d",num[i]);
			}
	}
	printf("\n");
}

/*OK*/
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

/*OK*/
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

/* contaDigitosStr
int main(){
	char numero[TAM_MAX];
	fgets(numero,TAM_MAX+1,stdin);
	printf("%d\n",contaDigitosStr(numero));
	return 0;
}*/

/*int main(){
	int vetor[TAM_MAX], tamanho,i;
	char numero[TAM_MAX];
	fgets(numero,TAM_MAX+1,stdin);
	tamanho=contaDigitosStr(numero);
	printf("\n");
	printf("\n");
	criaNumeraoDaString(numero,vetor,tamanho);
	for(i=0;i<TAM_MAX;i++){
		printf("%d",vetor[i]);
	}
	return 0;
}*/

/* mandaProFinal
int main(){
	int vetor[TAM_MAX], tamanho, i;
	char numero[TAM_MAX];
	fgets(numero,TAM_MAX+1,stdin);
	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);
	for (i=0;  i<TAM_MAX; i++){
		printf("%d",vetor[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	imprimeNumerao(vetor);
	printf("\n");
	return 0;
}*/

/* mandaProFinal
int main(){
	int vetor[TAM_MAX], tamanho,tamanhoDoVetor;
	char numero[TAM_MAX];
	fgets(numero,TAM_MAX+1,stdin);
	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);
	tamanhoDoVetor=tamanhoVetor(vetor);
	printf("%d",tamanhoDoVetor);
	printf("\n");
	return 0;
}*/

/*
int main(){
	int vetor[TAM_MAX], tamanho,tamanhoDoVetor;
	char numero[TAM_MAX];
	fgets(numero,TAM_MAX+1,stdin);
	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);
	tamanhoDoVetor=tamanhoVetor(vetor);
	imprimeNumerao(vetor);
	printf("tamanho = %d\n",tamanhoDoVetor);
	return 0;
}*/
/*maiorMenor
int main(){
	int vetor[TAM_MAX], vetor2[TAM_MAX],tamanho,tamanho2,resultado;
	char numero[TAM_MAX],numero2[TAM_MAX];

	fgets(numero,TAM_MAX+1,stdin);
	printf("\n");
	fgets(numero2,TAM_MAX+1,stdin);
	printf("\n");

	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);

	tamanho2=contaDigitosStr(numero2);
	criaNumeraoDaString(numero2,vetor2,tamanho2);
	mandaProFinal(tamanho2, vetor2);

	resultado=maiorMenor(vetor,vetor2,tamanho,tamanho2);
	printf("%d\n",resultado);
	return 0;
}*/

/* soma
int main(){
	int vetor[TAM_MAX], vetor2[TAM_MAX],tamanho,tamanho2,resultado;
	char numero[TAM_MAX],numero2[TAM_MAX];

	fgets(numero,TAM_MAX+1,stdin);
	fgets(numero2,TAM_MAX+1,stdin);

	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);

	tamanho2=contaDigitosStr(numero2);
	criaNumeraoDaString(numero2,vetor2,tamanho2);
	mandaProFinal(tamanho2, vetor2);

	soma(vetor,vetor2,tamanho,tamanho2);
	imprimeNumerao(vetor);
	return 0;
}*/

int main(){
	int vetor[TAM_MAX], vetor2[TAM_MAX],tamanho,tamanho2,resultado;
	char numero[TAM_MAX],numero2[TAM_MAX];

	fgets(numero,TAM_MAX+1,stdin);
	fgets(numero2,TAM_MAX+1,stdin);

	tamanho=contaDigitosStr(numero);
	criaNumeraoDaString(numero,vetor,tamanho);
	mandaProFinal(tamanho, vetor);

	tamanho2=contaDigitosStr(numero2);
	criaNumeraoDaString(numero2,vetor2,tamanho2);
	mandaProFinal(tamanho2, vetor2);

	subtrai(vetor,vetor2,tamanho,tamanho2);
	imprimeNumerao(vetor);
	return 0;
}
