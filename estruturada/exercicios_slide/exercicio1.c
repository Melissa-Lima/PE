#include <stdio.h>

int main(){

  float comissao,valor;

  scanf("%f", &valor);

  if (valor<=2500){
    comissao=30+0.017*valor;
    if (comissao>39){
      comissao=comissao;
    }
    else{
      comissao=39;
    }
  }
  else if(valor>2500 && valor<=6250){
    comissao=56+0.0066*valor;
  }
  else if(valor>6250 && valor<=20000){
    comissao=76+0.0034*valor;
  }
  else if(valor>20000 && valor<=50000){
    comissao=100+0.0022*valor;
  }
  else if(valor>50000 && valor<=500000){
    comissao=155+0.0011*valor;
  }
  else{
    comissao=255+0.0009*valor;
  }

  printf("%s%.2f\n","COMISSAO: R$",comissao);

  return 0;
}
