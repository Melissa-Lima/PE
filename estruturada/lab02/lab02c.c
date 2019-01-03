/*Melissa Lima - 11113815*/

#include <stdio.h>

int bissexto(int n){
		if (n%400==0 || (n%4==0 && n%100!=0)){
      return 1;
    }
    else{
      return 0;
    }

}

int validaData(int dia, int mes, int ano){
  if (((mes==4||mes==6||mes==9||mes==11)&&(dia>30))||(!bissexto(ano)&&dia>28)||(bissexto(ano)&&dia>29)||dia>31||ano<1||mes<1||dia<1||mes>12){
    return 0;
  }
  else{
    return 1;
  }
}

int main(){
  int dia,mes,ano,x,y,w;

  scanf("%d%d%d",&dia,&mes,&ano);

  while (1){
    if (!validaData(dia,mes,ano)){
      printf("%s\n","invalida");
      break;
    }

    if (mes==1 || mes==2){
      ano--;
    }

    if (mes==1){
      x=28;
    }
    else if(mes==2){
      x=31;
    }
    else if(mes==3){
      x=2;
    }
    else if(mes==4){
      x=5;
    }
    else if(mes==5){
      x=7;
    }
    else if(mes==6){
      x=10;
    }
    else if(mes==7){
      x=12;
    }
    else if(mes==8){
      x=15;
    }
    else if(mes==9){
      x=18;
    }
    else if(mes==10){
      x=20;
    }
    else if(mes==11){
      x=23;
    }
    else if(mes==12){
      x=25;
    }

    y = 5*(ano%4)+4*(ano%100)+6*(ano%400);
    w = (dia+x+y)%7;

    if (w==0){
      printf("%s\n","domingo");
    }
    else if (w==1){
      printf("%s\n","segunda");
    }
    else if (w==2){
      printf("%s\n","terca");
    }
    else if (w==3){
      printf("%s\n","quarta");
    }
    else if (w==4){
      printf("%s\n","quinta");
    }
    else if (w==5){
      printf("%s\n","sexta");
    }
    else if (w==6){
      printf("%s\n","sabado");
    }
    break;
  }
  return 0;
}
