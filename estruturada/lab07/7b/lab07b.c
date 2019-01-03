/*	Melissa Lima - 11113815 */

#include <stdio.h>

char *comeco;
char *fim;
char simbolo;
static int delimitador = 0;
/*Essa funcao calcula o tamanho de uma string (nao conta \n e \0)*/

int tamanhoStr(char str[]){
	int tamanho=0;
	int i;
	for (i=0; str[i]!='\0' && str[i]!='\n'; i++){
		tamanho++;
	}

	return tamanho;
}
/* dado duas strings, essa funcao vai retornar um ponteiro para uma palavra separadamente. A segunda string indica o fator que e usado para separar as palavras. A cada chamada, o ponteiro de retorno apontará para a a próxima palavra em relacao a palavra que foi retornada na ultima chamada. (mesmo funcionamento da strtok da biblioteca string.h).*/
char *strpok(char *str, char *delimiters){
	int i;
	int cont;
	int tamanhoD = tamanhoStr(delimiters);
	if(str!=NULL){
		comeco=str;
		fim=str;
	}

	if(str==NULL){
		comeco=fim;
		if(delimitador){
			*(fim-1)=simbolo;
		}
	}

	for(; *comeco!='\0' && *comeco!='\n'; comeco++, fim++){
		for(i=0; i<tamanhoD; i++){
			cont=0;
			if(*comeco==delimiters[i]){
				cont++;
				break;
			}
		}

		if(cont==0){

			for(; *comeco!='\0' && *comeco!='\n'; fim++){
				for(i=0; i<tamanhoD; i++){
					cont=0;
					if(*fim==delimiters[i]||*fim=='\n'){
						if(*fim==delimiters[i]){
							simbolo=delimiters[i];
							delimitador=1;
						}
						else{
							delimitador=0;
						}
						*fim='\0';
						fim++;
						return comeco;
					}
				}
			}
		}
	}

	return NULL;
}

int main(){
	char frase[181], delimitadores[11], *inicio;
	fgets(frase,181,stdin);
	fgets(delimitadores,11,stdin);
	inicio = strpok(frase, delimitadores);
	while (inicio != NULL) {
        printf("%s\n", inicio);
        inicio = strpok(NULL,delimitadores);
    }
	*(fim)='\0';
	printf("%s\n",frase);
	return 0;
}
