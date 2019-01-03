#include <stdio.h>

int soma(int vetor[], int tamanho, int resultado){
    int i;
    int soma=0;
    for(i=0; i<tamanho; i++){
        soma+=vetor[i]
    }
    if (soma==resultado){
        return 1;
    }
    return 0;
}

int multiplicacao(int a, int b, int resultado){
    int i;
    int mult=1;
    for(i=0; i<tamanho; i++){
        mult*=vetor[i]
    }
    if (mult==resultado){
        return 1;
    }
    return 0;
}

int divisao(int vetor[], int resultado);

int subtracao(int a, int b, int resultado);

int contaOperacoes(int vetor[], int tamanho, int resultado){
    int i;
    int cont=0;
    for (i=0; i<tamanho; i++){
        if (soma(vetor[i],vetor[i+1],resultado)){
            cont++;
        }
    }
}

int main(){
    int m;
    return 0;
}
