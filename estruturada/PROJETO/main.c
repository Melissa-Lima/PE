int main(){
    int vetor1[TAM_MAX], vetor2[TAM_MAX],*maior,*menor;
	char string1[TAM_MAX], string2[TAM_MAX], string3[TAM_MAX],operacao;
	int tamanho1,tamanho2,tamanhoMaior,tamanhoMenor,comparacao;
    string1[0]='0';
    string2[0]='0';

    while(string1[0]!='F' && string2[0]!='F' && string3[0]!='F'){
        fgets(string1,TAM_MAX+1,stdin);
        if((strin[0]!='-' && string1[1]!='\n' && string1[0]!='+')){
            tamanho1=contaDigitosStr(string1);
    		criaNumeraoDaString(string1,vetor1,tamanho1);
    		mandaProFinal(tamanho1,vetor1);
        }
        else{
            operacao=string1[0];
        }
        fgets(string2,TAM_MAX+1,stdin);
        if((strin[0]!='-' && string1[1]!='\n' && string1[0]!='+')){
            tamanho2=contaDigitosStr(string2);
    		criaNumeraoDaString(string2,vetor2,tamanho2);
            mandaProFinal(tamanho2,vetor2);
        }
        else{
            operacao=string1[0];
        }
        comparacao=maiorMenor(vetor1,vetor2,tamanho1,tamanho2);
        if(comparacao<1){
            maior=vetor2;
            menor=vetor1;
            tamanhoMaior=tamanho2;
            tamanhoMenor=tamanho1;
        }else{
            maior=vetor1;
            menor=vetor2;
            tamanhoMaior=tamanho1;
            tamanhoMenor=tamanho2;
        }
        switch(operacao[0]){
            case('+'):
                if(maior[0]==1 && menor[0]==1){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==1 && menor[0]==0){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                    maior[0]=1;
                }else if(maior[0]==0 && menor[0]==1){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==0 && menor[0]==0){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                }
                imprimeNumerao(maior);
                break;

            case('-'):
                if(maior[0]==1 && menor[0]==1){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                }else if(maior[0]==1 && menor[0]==0){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                    maior[0]=0;
                }else if(maior[0]==0 && menor[0]==1){
                    soma(maior,menor,tamanhoMaior,tamanhoMenor);
                    if(maior==vetor2){
                        maior[0]=1;
                    }else{
                        maior[0]=0;
                    }
                }else if(maior[0]==0 && menor[0]==0){
                    subtrai(maior,menor,tamanhoMaior,tamanhoMenor);
                    if(menor==vetor1){
                        maior[0]=1;
                    }
                }
                imprimeNumerao(maior);
                break;
            }
    }
    return 0;
}
