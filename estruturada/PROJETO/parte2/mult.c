void multiplicacao(int num1[], int multiplicador){
	int i,j,copia[TAM_MAX],vaium=0;

	if(tamanho2==0 || tamanho1==0){
		zeraVetor(num1, TAM_MAX-tamanho1);
        return;
	}

	for(i=0; i<TAM_MAX; i++){
		copia[i]=num1[i];
	}

	for(j=TAM_MAX-1; j>=0; j--){
		if((multiplicador*copia[j])+vaium<10){
			num1[j]=copia[j]*multiplicador+vaium;
			vaium=0;
		}else{
			num1[j]=(copia[j]*multiplicador+vaium)%10;
			vaium=((copia[j]*multiplicador+vaium)/10);
		}
	}
}
