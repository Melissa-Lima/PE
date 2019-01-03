#include <stdio.h>
#include <stdlib.h>

struct Carta {
    char nome[30];
    int caracteristicas[8];
};
typedef struct Carta Carta;

int main(int argc, char *argv[]){
    FILE *primeiroarq;
    int q1,q2,n,comeco,atributo,i,j,jogadas,;
    Carta *deckV;
    Carta *dckL;

    primeiroarq=fopen(argv[1],"r");

    fscanf(primeiroarq,"%d%d%d\n",&q1,&q2,&n);
    cartasV=malloc(q1*sizeof(Carta));
    cartasL=malloc(q2*sizeof(Carta));

    for(i=0; i<q1; i++){
        fgets(cartasV[i].nome,30,primeiroarq);
        for(j=0; j<8; j++){
            fscanf(primeiroarq,"%d",&atributo);
            cartasV[i].caracteristicas[j]=atributo;
        }
        fscanf(primeiroarq,"\n");
    }

    for(i=0; i<q1; i++){
        for(j=0; j<8; j++){
            printf("%d ",cartasV[i].caracteristicas[j]);
        }
        printf("\n");
    }

    for(i=0; i<q2; i++){
        fgets(cartasL[i].nome,30,primeiroarq);
        for(j=0; j<8; j++){
            fscanf(primeiroarq,"%d",&atributo);
            cartasL[i].caracteristicas[j]=atributo;
        }
        fscanf(primeiroarq,"\n");
    }

    for(i=0; i<q2; i++){
        for(j=0; j<8; j++){
        }
        printf("\n");
    }
    fclose(primeiroarq);

    scanf("%d",&jogadas);

    for(i=0; i<jogadas; i++){
        scanf()
    }
}
