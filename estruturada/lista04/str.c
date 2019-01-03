#include <stdio.h>
#include <string.h>

int anagrama(char palavra1[21], char palavra2[21]){
	int i,j;
	int cont=0;
	int letrasIguais=0;
	
	if (strlen(palavra1)!=strlen(palavra2)){
		return 0;
	}

	
	for (i=0; palavra1[i]!='\0'; i++){
		cont=0;
		for (j=0; palavra2[j]!='\0'; j++){
			if (palavra1[i]==palavra2[j]){
				cont++;
				if (cont>1 || cont==0){
					return 0;
				}
				letrasIguais++;
			}
		}
	}
	
	if (letrasIguais==strlen(palavra1)){
		return 1;
	}
	return 0;
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
