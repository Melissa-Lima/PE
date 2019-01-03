#include <stdio.h>

int tamanhoStr(char str[]){
	int tamanho=0;
	int i;
	for (i=0; str[i]!='\0' && str[i]!='\n'; i++){
		tamanho++;	
	}

	return tamanho;
}

/*FUNCAO QUE CONSIDERA UM ESPACO NO MAX
int palindromi(char str[]){
	int inicio;
	int fim=tamanhoStr(str)-1;

	for (inicio=0; fim-inicio>=0 ; inicio++,fim--){
		if (str[inicio]!=str[fim]){
			return 0;
		}
	}
	return 1;	
}*/

/* FUNCAO CONSIDERA MAIS DE UM ESPACO*/
int palindromi(char str[]){
	int inicio;
	int fim=tamanhoStr(str)-1;

	for (inicio=0; fim-inicio>=0 ; inicio++,fim--){
		while (str[inicio]==' '){
			inicio++;		
		}
		while (str[fim]==' '){
			fim--;
		}
		if (str[inicio]!=str[fim]){
			return 0;		
		}
	}
	return 1;	
}

/*FUNCAO NAO CONSIDERA ESPACO
int palindromi(char str[]){
	int inicio;
	int fim=tamanhoStr(str)-1;

	for (inicio=0; fim-inicio>=0 ; inicio++,fim--){
		if (str[inicio]==' '){
			inicio++;		
		}if(str[fim]==' '){
			fim--;
		}
		if (str[inicio]!=str[fim]){
			return 0;		
		}
	}
	return 1;	
}*/

int main (){
	printf("%d\n",palindromi("saudavel leva duas"));
	printf("%d\n",palindromi("paap"));
	printf("%d\n",palindromi("pat"));
	printf("%d\n",palindromi("ABB  A"));
	return 0;
}
