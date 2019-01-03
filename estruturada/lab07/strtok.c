#include <stdio.h>
#include <string.h>

int main() {
    char frase[] = "  Vida  longa  e próspera.";
    char *inicio;

    printf("Dividindo a string \"%s\" em tokens:\n", frase);

    inicio = strtok(frase, " .");
    printf("%s\n",inicio);
    while (inicio != NULL) {
        printf("%s\n", inicio);
        inicio = strtok(NULL, " ,.");
    }

    return 0;
}
