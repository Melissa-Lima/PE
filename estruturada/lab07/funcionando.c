#include <stdio.h>

char *comeco;
char *fim;
char simbolo;

/*int tamanhoStr(char str[]){
	int i=0;
	int tamanho=0;
	while(str[i]!='\0'){
		tamanho++;
	}
	printf("%d\n",tamanho);
	return tamanho;
}*/

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

	if(str!=NULL){
		comeco=str;
		fim=str;
	}

	if(str==NULL){
		comeco=fim;
		*(fim-1)=simbolo;
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


int main() {
    char frase[] = "As necessidades de muitos soprepujam as necessidades de poucos, ou de um.";
    char *inicio;
    printf("Dividindo a string \"%s\" em tokens:\n", frase);
    inicio = strpok(frase, " .");
    while (inicio != NULL) {
        printf("%s\n", inicio);
        inicio = strpok(NULL, " ,.");
    }
	printf("%s\n",frase);
    return 0;
}
