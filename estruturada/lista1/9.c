#include <stdio.h>

int main(){

  float a,b,c,maior;

  scanf("%f%f%f",&a,&b,&c);

  if (a>b && a>c){
    maior=a;
  }
  else if (b>a && b>c){
    maior=b;
  }
  else{
    maior=c;
  }

  printf("%.3f\n",maior);

  return 0;
}
