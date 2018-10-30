#include <stdio.h>
#include <string.h>

int repeticao(char palavra[], char letra){
	int i;
	int cont=0;
	for (i=0; palavra[i]!='\0' && palavra[i]!='\n'; i++){
		if (palavra[i]==letra){
			cont++;
		}
	}
	return cont;
}

int anagrama(char palavra1[], char palavra2[]){
	int i;
	
	for (i=0; palavra1[i]!='\0' && palavra1[i]!='\n'; i++){
		if(repeticao(palavra1,palavra1[i])!=(repeticao(palavra2,palavra1[i]))){
			return 0;
		}
	}
	return 1;
}

int main(){

	int verifica;
	
	char palavra1[21], palavra2[21];
	
	scanf("%s",palavra1);
	scanf("%s",palavra2);
	
	verifica = anagrama(palavra1,palavra2);
	printf("%d\n",verifica);
	
	return 0;
}
