#include <stdio.h>

int main(){


	int golpe = 1;
	int rounds = 0;
	int score = 0;
	int ultimoGolpe=0;

	while (golpe!=0){
		
		while(1){
			scanf("%d",&golpe);
			score+=golpe;
			if (golpe>=0 && ultimoGolpe<0){
				break;
			}
			
			ultimoGolpe=golpe;
		}
		
		score-=golpe;
		if (score!=0)
			rounds += (score > 0)? 1:-1; /*operador ternario */

		/*if (score>0){
			rounds++;
		}
		else if (score>0){
			rounds--;
		}
		score=golpe;*/
	}
	
	if (rounds!=0)
		printf("%s venceu\n", (rounds>0)? "Ryu" : "Ken");
	else
		printf("empatou\n");

	/*if (rounds>0){
		printf("Ryu venceu\n");
	}
	
	else if (rounds>0){
		printf("Ryu venceu\n");
	}
	
	else{
		printf("empatou\n");
	}*/

	return 0;
}
