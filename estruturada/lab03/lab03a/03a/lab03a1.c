#include <stdio.h>

int main(){


	int golpe = 1;
	int rounds = 0;
	int scoreFinal = 0;
	
	scanf("%d",&golpe); /*precisam de um tratamento diferenciado pois vai acabar somando negativo na pontuacao do ryu*/
	while (golpe !=0){
		do {   
			scanf("%d",&golpe);
			scoreFinal+=golpe;
		} while (golpe>0);
		scoreFinal-=golpe;	
		
		while (golpe<0){
			scoreFinal+=golpe;
			scanf("%d", &golpe);
		}
	
		
		if (scoreFinal > 0){
			rounds++;
		}	else if (scoreFinal < 0){
				rounds--;				/*quem ganhou cada round*/
		} 
		
		scoreFinal=golpe; /*ja coloca o primeiro golpe no novo score*/
	}
	
	if (rounds>0){
		printf("Ryu venceu\n");
	}
	
	else if (rounds>0){
		printf("Ryu venceu\n");
	}
	
	else{
		printf("empatou\n");
	}
	return 0;
}
