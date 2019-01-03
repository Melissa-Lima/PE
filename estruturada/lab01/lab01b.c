#include <stdio.h>

int main(){
  float h,v,d,T,t,tQueda,vx,tx; /*h = altura, v = distância no eixo y, d = distância x, T = empuxo, t = tempo que deve ser adiconado
                                o micro explosivo, tQueda = tempo pra chegar ao chao, vx = velocidade no eixo x, tx = velocidade para chegar em d.*/

  scanf("%f%f%f%f", &h,&v,&d,&T);

  tQueda=h/v;
  vx=T;
  tx=d/vx;
  t=tQueda-tx;

  printf("%.3f\n", t); /* Deixa 3 casas após a vírgula. */

  return 0;

}
