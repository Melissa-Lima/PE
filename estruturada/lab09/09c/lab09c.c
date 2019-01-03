/* Melissa Lima - 11113815 */

#include <stdio.h>
#include <stdlib.h>

struct Carta {
    char nome[30];
    int caracteristicas[8];
};
typedef struct Carta Carta;

void organizaDeckVencedor(int *tamDeck, Carta *deck, Carta cartaVencedor, Carta cartaPerdedor){
    int i,tamNovo;
    Carta *aux;
    tamNovo=(*tamDeck)+1;
    aux=malloc(tamNovo*sizeof(Carta));
    for(i=0; i<(*tamDeck)-1; i++){
        aux[i]=deck[i+1];
    }

    aux[tamNovo-2]=cartaVencedor;
    aux[tamNovo-1]=cartaPerdedor;
    free(deck);
    deck=aux;
    *tamDeck=tamNovo;
}

void organizaDeckPerdedor(int *tamDeck, Carta *deck){
    int i,tamNovo;
    Carta *aux;
    tamNovo=(*tamDeck)-1;
    aux=malloc(tamNovo*sizeof(Carta));
    for(i=0; i<tamNovo; i++){
        aux[i]=deck[i+1];
    }
    free(deck);
    deck=aux;
    *tamDeck=tamNovo;
}

int main(int argc, char *argv[]){

    FILE *primeiroArq;
    FILE *Arqsaida;
    int q1,q2,n,elemento,i,j,jogadas,*tamDeckV,*tamDeckL,*tamDeckP,*tamDeckS,atributo,*auxiliar;
    Carta *deckV,*deckL,*primeiro,*segundo,*aux;

    primeiroArq=fopen(argv[1],"r");
    fscanf(primeiroArq,"%d%d%d\n",&q1,&q2,&n);
    deckV=malloc(q1*sizeof(Carta));
    deckL=malloc(q2*sizeof(Carta));
    *tamDeckV=&q1;
    *tamDeckL=&q2;

    for(i=0; i<q1; i++){
        fgets(deckV[i].nome,30,primeiroArq);
        for(j=0; j<8; j++){
            fscanf(primeiroArq,"%d",&elemento);
            deckV[i].caracteristicas[j]=elemento;
        }
        fscanf(primeiroArq,"\n");
    }

    for(i=0; i<q2; i++){
        fgets(deckL[i].nome,30,primeiroArq);
        for(j=0; j<8; j++){
            fscanf(primeiroArq,"%d",&elemento);
            deckL[i].caracteristicas[j]=elemento;
        }
        fscanf(primeiroArq,"\n");
    }

    fclose(primeiroArq);

    primeiro=(n==1?deckV:deckL);
    segundo=(primeiro==deckV?deckL:deckV);
    *tamDeckP=(primeiro==deckV?q1:q2);
    *tamDeckS=(*tamDeckP==q1?q2:q1);

    scanf("%d",&jogadas);
    Arqsaida=fopen(argv[2],"w");

    for(i=0; i<jogadas; i++){
        scanf("%d",&atributo);
        if(atributo==1||atributo==2||atributo==4||atributo==5){
            if((primeiro[0].caracteristicas[atributo])>=(segundo[0].caracteristicas[atributo])){
                organizaDeckVencedor(tamDeckP,primeiro,primeiro[0],segundo[0]);
                organizaDeckPerdedor(tamDeckS,segundo);
            }else{
                organizaDeckVencedor(tamDeckS,segundo,segundo[0],primeiro[0]);
                organizaDeckPerdedor(tamDeckP,primeiro);
                aux=primeiro;
                primeiro=segundo;
                segundo=aux;
                auxiliar=*tamDeckP;
                tamDeckP=&tamDeckS;
                *tamDeckS=auxiliar;
            }
        }else{
            if((primeiro[0].caracteristicas[atributo])<=(segundo[0].caracteristicas[atributo])){
                organizaDeckVencedor(tamDeckP,primeiro,primeiro[0],segundo[0]);
                organizaDeckPerdedor(tamDeckS,segundo);
            }else{
                organizaDeckVencedor(tamDeckS,segundo,segundo[0],primeiro[0]);
                organizaDeckPerdedor(tamDeckP,primeiro);
                aux=primeiro;
                primeiro=segundo;
                segundo=aux;
                auxiliar=*tamDeckP;
                tamDeckP=&tamDeckS;
                *tamDeckS=auxiliar;
            }
        }
    }
    fprintf(Arqsaida,"%d %d %d\n",q1,q2,n);

    for(i=0; i<q1; i++){
        fprintf(Arqsaida,"%s\n",deckV[i].nome);
        for(j=0; j<8; j++){
            if(j!=7){
                fprintf(Arqsaida,"%d ",deckV[i].caracteristicas[i]);
            }else{
                fprintf(Arqsaida,"%d\n",deckV[i].caracteristicas[i]);
            }

        }
    }

    for(i=0; i<q2; i++){
        fprintf(Arqsaida,"%s\n",deckL[i].nome);
        for(j=0; j<8; j++){
            if(j!=7){
                fprintf(Arqsaida,"%d ",deckL[i].caracteristicas[i]);
            }else{
                fprintf(Arqsaida,"%d\n",deckL[i].caracteristicas[i]);
            }
        }
    }
    fclose(Arqsaida);
    return 0;
}
