/* Melissa Lima - 11113815 */

#include <stdio.h>
#include <stdlib.h>

FILE *arqEnt;
FILE *arqSaida;

void removeComentarios(char *entrada, char *saida){
    char aux[20];
    char aux2[20];
    char auxiliar;
    int i,cont,j;
    arqEnt=fopen(entrada,"r");
    arqSaida=fopen(saida,"w");
    while(fgets(aux,20,arqEnt)!=NULL){
        fprintf(arqSaida,"%s",aux);
    }
    fclose(arqEnt);
    fclose(arqSaida);
    arqSaida=fopen(saida,"r+");
    puts("entrei aqui");
    while(fgets(aux2,20,arqSaida)!=NULL){
        for(i=0; i<19; i++){
            if(aux2[i]=='/'){
                if(aux2[i+1]=='/'){
                    for(j=2; j<19; j++){
                        if(aux2[j]!='\n'){
                            aux2[j]=' ';
                        }else{
                            break;
                        }
                    }
                    fprintf(arqSaida,"%s",aux2);
                    break;
                }else if(aux2[i+1]=='*'){
                    for(j=2; j<19; j++){
                        if(aux2[j]!='*'&&aux2[j+1]!='/'){
                            aux2[j]=' ';
                        }if(aux2[j]=='*'&&aux2[j+1]=='/'){
                            aux2[j]=' ';
                            aux2[j+1]=' ';
                            break;
                        }
                }
                    fprintf(arqSaida,"%s",aux2);
                }
            }
        }
    }
}

int main(int argc, char *argv[]){

    removeComentarios(argv[1],argv[2]);

    return 0;
}
