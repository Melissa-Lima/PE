#include <stdio.h>

int main(){

  int golpeRyu=0;
  int golpeKen=0;
  int roundRyu=0;
  int roundKen=0;
  int golpe=1;
  int golpeAnterior=-1;

  while (golpe!=0){
    scanf("%d", &golpe);
    if (golpeAnterior<0 && (golpe>=0)){
      if (golpeRyu>golpeKen){
        roundRyu++;
        /*printf("round ryu++\n");*/
      } else if (golpeKen>golpeRyu){
        roundKen++;
        /*printf("round ken++\n");*/
      }
      golpeRyu=0;
      golpeKen=0;
      /*printf("zerei os golpes do K e R\n");*/
    }
    if (golpe>0){
      golpeRyu+=golpe;
      /*printf("atualizei golpe Ryu\n");*/
    }
    if (golpe<0){
      golpeKen-=golpe;
      /*printf("atualizei golpe ken\n");*/
    }
    golpeAnterior=golpe;
    /*printf("atualizei golpe anterior\n");*/
  }

  
  if (roundRyu>roundKen){
    printf("Ryu venceu\n");
  } else if (roundKen>roundRyu){
    printf("Ken venceu\n");
  } else{
    printf("empatou\n");
  }

  return 0;
}
