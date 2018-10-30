#include <stdio.h>

int primo(n){
	int i;
	int cont=0;
	if (n==1){
		return 0;
	}
	for (i=1;  i<=n/2; i++){
		if (n%i==0){
			cont++;
			if (cont>1){
				return 0;
			}
		}
	}
	return 1;
}


int main(){
	int resultado=primo(1);
	printf("%d\n",resultado);
	return 0;
}
