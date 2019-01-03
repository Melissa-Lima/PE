/*Melissa Lima - 11113815*/

#include <stdio.h>

int main () {

  float d,h,a,b,c,r,volume;

  scanf("%f %f %f %f %f", &d, &h, &a, &b, &c);

  r=d/2.0;
  volume=3.14*r*r*h*1000;

    if (volume>a){
      volume-=a;
      printf("posto A foi reabastecido\n");
    }
    else{
      printf("posto A nao foi reabastecido\n");
    }
    if (volume>b){
      volume-=b;
      printf("posto B foi reabastecido\n");
    }
    else{
      printf("posto B nao foi reabastecido\n");
    }
    if (volume>c){
      volume-=b;
      printf("posto C foi reabastecido\n");
    }
    else{
      printf("posto C nao foi reabastecido\n");
    }

    return 0;
}
