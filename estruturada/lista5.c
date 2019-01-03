#include <stdio.h>

/*int main() {
    int vet[] = {4,9,12};
    int i, *ptr;
    ptr = vet;
    for (i = 0; i < 3; i++) {
        printf("%d ", (*ptr)++);
    }
    return 0;
}

 Por que ele ta printando 4 5 6 e não 5 6 7 quando eh (*ptr)++ */

int main(){
    int i = 3;
    int *p;
    p = &i;
    printf("%d", **&p);
    return 0;
}
