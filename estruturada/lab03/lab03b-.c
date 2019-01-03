#include <stdio.h>

int main(){

    int r,andar;
    int yAndado=0;
    int xAndado=0;
    char virar='a';
    char H;
    char V;
    char inicializacao;

    int Vp=1;    /*Vertical Positivo*/
    int Vn=0;    /*Vertical Negativo*/
    int Hp=0;    /*Horizontal Positivo*/
    int Hn=0;    /*Horizontal Negativo*/

    scanf("%d",&r);
    printf("raio\n");
    scanf("\n%c",&inicializacao);

    if (inicializacao!=('F')){
      if (inicializacao==('L')){
        Vp=0;
        Hn=1;
      }else{
        Vp=0;
        Hp=1;
      }
    }

    while(virar!='X'){

        scanf("%d",&andar);

        if (Vp || Vn){
            if (Vp){
                yAndado+=andar;
                printf("y = %d\n",yAndado);
            } else{
                V='S';
                yAndado-=andar;
                printf("y = %d\n",yAndado);
            }

            if (yAndado>0){
              V='N';
              printf("V = %c\n",V);
            }else{
              V='S';
              printf("V = %c\n",V);
            }

            /*if (xAndado<0 && yAndado>0){
              if (((xAndado*-1)+yAndado)>r){
                break;
              }
            }else if (yAndado<0 && xAndado>0){
              if (((yAndado*-1)+xAndado)>r){
                break;
              }
            }else if (xAndado>0 && yAndado>0){
              if (xAndado+yAndado>r){
                break;
              }
            }*/

            scanf("\n%c",&virar);

            if ((Vp&&(virar=='R')) || (Vn&&(virar=='L'))){
                Hp=1;
                Hn=0;
                printf("Hp=%d, Hn=%d\n",Hp,Hn);
            } else{
                Hp=0;
                Hn=1;
                printf("Hp=%d, Hn=%d\n,",Hp,Hn);
            }

            Vp=0;
            Vn=0;

        }else{
            if (Hp){
                xAndado+=andar;
                printf("x = %d\n",xAndado);
            } else{
                xAndado-=andar;
                printf("x = %d\n",xAndado);
            }

            if (xAndado>0){
              H='E';
              printf("H = %c\n",H);
            }else{
              H='W';
              printf("H = %c\n",H);
            }

            /*if (xAndado<0 && yAndado>0){
              if (((xAndado*-1)+yAndado)>r){
                break;
              }
            }else if (yAndado<0 && xAndado>0){
              if (((yAndado*-1)+xAndado)>r){
                break;
              }
            }else if (xAndado>0 && yAndado>0){
              if (xAndado+yAndado>r){
                break;
              }
            }*/

            scanf("\n%c",&virar);

            /*if ((Hp&&(virar=='L')) || (Hn&&(virar=='R'))){
                Vp=1;
                Vn=0;
                printf("Vp=%d, Vn=%d\n",Vp,Vn);
            } else{
                Vp=0;
                Vn=1;
                printf("Vp=%d, Vn=%d\n",Vp,Vn);
            }*/

            Hp=0;
            Hn=0;

        }
      }

      if (xAndado<0){
        xAndado=xAndado*(-1);
      } else if (yAndado<0){
        yAndado=yAndado*(-1);
      }

    printf("%d%c %d%c",xAndado,H,yAndado,V);

    return 0;
}
