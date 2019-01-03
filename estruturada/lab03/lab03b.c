/*Melissa Lima*/

#include <stdio.h>

int main(){

  int r,K,andar;
  char direcao = 'i';
  int xAndado=0;
  int yAndado=0;
  int verticalAtual=0;
  int horizontalAtual=0;

  scanf("%d",r);

  vertical=2*r;
  horizontal=2*r;
  verticalAtual=r;
  horizontalAtual=r;

  while (direcao=!'X'){
    scanf("%c %d", andar,K); /*andar K quilometros*/
    scanf("%c", direcao); /*direcao pode ser direita ou esquerda (R ou L")*/
    /*if (direcao=='i'){
      verticalAtual-=K;
    }*/

    else if (direcao=='R'){
      posicaoAnterior++;
    }

    else{
      posicaoAnterior--;
    }
    if (posicaoAnterior%2==0){

    }
  }

  return 0;
}
