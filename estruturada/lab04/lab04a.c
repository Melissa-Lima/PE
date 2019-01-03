/*Melissa Lima - 11113815*/
#include <stdio.h>
#include <math.h>

double termo_sth(double z, int i){
	double base_exp = (2*i)-1;
	double interna = (z-1)/(z+1);
	return (1/base_exp)*(pow(interna,base_exp))*2;
}

double sth(double z, int J){
	if (J==0)
		return 0;
	return termo_sth(z,J)+sth(z,J-1);
}

double termo_sta(double z, int i){
	double sinal,valor;
	sinal=pow(-1,i-1);
	valor=pow(z-1,i)/i;
	return (sinal*valor);
} 

double sta(double z,int I){
	if (I==0)
		return 0;
	return termo_sta(z,I)+sta(z, I-1);
}



int main(){
	double z,padrao,stav,sthv;
	int i, j;
	scanf("%lf%d%d",&z,&i,&j);

	padrao = log(z);
	stav=sta(z,i);
	sthv=sth(z,j);
	
	printf("%.6f %.6f %.6f\n",padrao,stav,sthv);
	
	return 0;
}

/* site c plusplus*/
