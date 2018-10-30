/*Melissa Lima - 11113815*/

#include <stdio.h>

int main(){

  int r, K, verticalAtual, horizontalAtual;
  int x=0;
  int y=0;
  int posicaoAnterior=0;
  char direcao,andar;

  scanf("%d",r);

  vertical=2*r;
  horizontal=2*r;
  verticalAtual=r;
  horizontalAtual=r;

  while (direcao=!'X'){
    scanf("%c %d", andar,K);        /*andar K quilometros*/
    scanf("%c", direcao);           /*direcao que o Wall-E virar pode ser direita ou esquerda (R ou L")*/

    if (posicaoAnterior%2==0){      /*posicaoAnterior par significa que ele esta olhando para a vertical*/
                                    /*saber se ele esta abaixo do centro ou acima do centro*/
      if (blabla){

      }
      else{
        break;
      }
    }
    else{
      if (){

      }
      else{
        break;
      }
    }

    if (direcao=='R'){
      posicaoAnterior++;
    }

    else{                           /*posicaoAnterior impar significa que ele esta olhando para a horizontal*/
      posicaoAnterior--;
    }
  }

    /*printf("%d%c %d%c",x,H,y,V);*/      /*printa a posicao atual, ex: 4E 5N*/

  return 0;
}
