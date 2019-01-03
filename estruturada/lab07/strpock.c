#include <stdio.h>

char *comeco;
char *fim;
char simbolo;

int tamanhoStr(char str[]){
	int tamanho=0;
	int i;
	for (i=0; str[i]!='\0' && str[i]!='\n'; i++){
		tamanho++;
	}

	return tamanho;
}
char *strpok(char *str, char *delimiters){
	int i;
	int cont;
	int tamanhoD = tamanhoStr(delimiters);
	printf("%s\n",str);
	if(str!=NULL){
		comeco=str;
		fim=str;
	}

	if(str==NULL){
		comeco=fim;
	}

	for(; *comeco!='\0'; comeco++, fim++){
		for(i=0; i<tamanhoD; i++){
			cont=0;
			if(*comeco==delimiters[i]){
				cont++;
				break;
			}
		}

		if(cont==0){

			for(; *comeco!='\0'; fim++){
				for(i=0; i<tamanhoD; i++){
					cont=0;
					if(*fim==delimiters[i]){
						simbolo=delimiters[i];
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
	return 0;
}
