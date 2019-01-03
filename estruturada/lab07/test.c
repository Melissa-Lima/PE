#include <stdio.h>

char *comeco;
char *fim;

int tamanhoStr(char str[]){
	int tamanho=0;
	int i;
	for (i=0; str[i]!='\0' && str[i]!='\n'; i++){
		tamanho++;
	}

	return tamanho;
}

char *strpok(char *str,char *delimiters){
    int i,cont;
    int tamanhoD = tamanhoStr(delimiters);

    if (str==NULL && *comeco=='\0'){
        return NULL;
    }

    for(; *comeco!='\0'; comeco++, fim++){
        cont=0;
        for(i=0; i<tamanhoD; i++){
            if(*comeco==delimiters[i]){
                cont++;
                break;
            }
        }

        if(cont==0){
            while(1){
                for(i=0; i<tamanhoD; i++){
                    if(*fim==delimiters[i]){
                        *fim='\0';
                        fim++;
                        comeco=fim+1;
                        return comeco;
                    }
                    fim++;
                }
            }
        }
    }
    return NULL;
}

int main() {
    char frase[] = "  Vida  longa  e próspera.";
    char *inicio;
	comeco=frase;
	fim=frase;
    printf("Dividindo a string \"%s\" em tokens:\n", frase);
    inicio = strpok(frase, " .");
	printf("%s\n",frase);
    while (inicio != NULL) {
        printf("%s\n", inicio);
        inicio = strpok(NULL, " ,.");
    }
    return 0;
}
