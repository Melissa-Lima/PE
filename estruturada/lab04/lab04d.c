#include <stdio.h>

int calculaPeso(int pe, int de, int pd, int dd){
  int peso = pe*de+pd*dd;
  return peso;
}

int calculaJmobil(int pe, int de, int pd, int dd){
  int pe2, de2, pd2, dd2, peso2e,peso2d;
  if (pe!=0 && pd!=0){
    return calculaPeso(pe,de,pd,dd);
  }
  if (pe==0){
  scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    peso2e=calculaJmobil(pe2,de2,pd2,dd2);
    printf("%d\n",peso2e);
    return peso2e+calculaJmobil(peso2e,de,pd,dd);
  }
    scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    peso2d=calculaJmobil(pe2,de2,pd2,dd2);
    printf("%d\n",peso2d);
    return peso2d+calculaJmobil(pe,de,peso2d,dd);
}
/*int calculaJmobil(int pe, int de, int pd, int dd){
  int pesoE, pesoD, pe2,de2,pd2,dd2;
  if (pe!=0 && pd!=0){
    pesoE=calculaPesoEsquerda(pe,de);
    pesoD=calculaPesoDireita(pd,dd);
  }else if (pe==0){
    scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    pesoE=calculaPesoEsquerda(pe2,pe2);
  }else if (pd==0){
    scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    pesoD=calculaPesoDireita(pd2,dd2);
  }
  return pesoE+pesoD;
}*/
/*int calculaJmobil(int pe, int de, int pd, int dd){
  int pe2, de2, pd2, dd2, peso2e,peso2d;
  if (pe!=0 && pd!=0){
    return pe*de+pd*dd;
  }if (pe==0){
    scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    peso2e=calculaJmobil(pe2,de2,pd2,dd2);
  }else if(pd==0){
    scanf("%d %d %d %d\n",&pe2,&de2,&pd2,&dd2);
    peso2d=calculaJmobil(pe2,de2,pd2,dd2);
  }
  return peso2e+peso2d;
}*/

int main(){

  int peso;

  peso=calculaJmobil(0,4,0,5);
  printf("%d\n",peso);
  return 0;
}
