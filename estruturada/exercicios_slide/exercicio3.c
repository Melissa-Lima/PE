#include <stdio.h>

int main(){

  float temperatura,conversao;
  char tempDada;
  scanf ("%c%f",&tempDada,&temperatura);

  if (tempDada=='C'){ /* conversao de Celsius para Fahrenheit */
    conversao=(temperatura*(9.0/5.0))+32;
  }
  else if (tempDada=='F'){
    conversao=(temperatura-32)*(5.0/9.0);
  }

  printf("%.3f\n",conversao);
  return 0;
}
