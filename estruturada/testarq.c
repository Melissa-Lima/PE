#include <stdio.h>

int main(int argc, char *argv[]) {
 int i;
 FILE *primeiroarq;
 char buffer[10];
 primeiroarq=fopen("arqintest","r");
 fscanf(primeiroarq,"%d\n",&i);
 while(fgets(buffer,2,primeiroarq)){
     printf("%s",buffer);
 }
 return 0;
}
