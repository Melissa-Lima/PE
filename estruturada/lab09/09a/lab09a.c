/* Melissa Lima - 11113815 */

#include <stdio.h>
#include <stdlib.h>

void removeComentarios(FILE *arqEnt, FILE *arqSaida){
    char aux[20];
    int i;
    while(fgets(aux,20,arqEnt)!=NULL){
        for(i=0; i<18; i++){
            if(aux[i]=='/'){
                if(aux[i+1]=='*'){
                    while(1){
                        fgets(aux,20,arqEnt);
                        for(i=0; i<18; i++){
                            if(aux[i]=='*' && aux[i+1]=='/'){
                                fgets(aux,20,arqEnt);
                                break;
                            }
                        }
                        break;
                    }
                }else if(aux[i]=='/'){
                    fgets(aux,20,arqEnt);
                }
            }
            fprintf(arqSaida,"%s",saida);
        }
    }
}

int main(int argc, char *argv[]){
    FILE *entrada;
    FILE *saida;

    entrada=fopen(argv[0],"r");
    fopen("arqXX.test",saida);

    removeComentarios(entrada,saida);

    fclose(entrada);
    fclose(saida);

    return 0;
}
