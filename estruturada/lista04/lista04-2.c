 #include <stdio.h>
 
 
 int main(){
 
 	 int i,numero;
	 int tamanho = 30;
	 int j=tamanho-1;
	 int vetorInverso[30];
	 
	 for (i=0; i<tamanho; i++,j--){
	 	scanf("%d",&numero);
	 	vetorInverso[j]=numero;
	 }
 	
 	for (i=0; i<tamanho; i++){
 		printf("%d\n",vetorInverso[i]);
 	}
 	return 0;
 }
