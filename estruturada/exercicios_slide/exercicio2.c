#include <stdio.h>

int main(){

  char conceito;
  float P1,P2,L,T,MF;

  scanf("%f%f%f%f",&P1,&P2,&L,&T);

  if (P1+P2<10||L<5||T<5){
    if ((P1+P2)<L && P1+P2<T){
      MF=P1+P2;
    }
    else if(L<(P1+P2) && L<T){
      MF=L;
    }
    else{
      MF=T;
    }
  }
  else{
    MF=0.2*P1+0.3*P2+0.3*L+0.2*T;
  }

  if(MF>=8.5){
    conceito='A';
  }
  else if(7<=MF && MF<8.5){
    conceito='B';
  }
  else if(6.0<=MF && MF<=7.0){
    conceito='C';
  }
  else if(5.0<=MF && MF<6.0){
    conceito='D';
  }
  else{
    conceito='F';
  }

  printf("Conceito final: %c\n", conceito);

  return 0;
}
