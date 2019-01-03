#include <stdio.h>

int main (){
    int vi, xi, yi, xf, yf, t, d, v;

    scanf("%d%d%d%d%d%d", &vi,&xi,&yi,&xf,&yf,&t);

    d=(xf-xi)+(yf-yi);
    v=vi+(d*t);
    printf("%d\n",v);

    return 0;
}
