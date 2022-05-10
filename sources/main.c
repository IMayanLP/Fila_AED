#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.c"

int main(){
    Fila *fds, *fdsB;
    fds = criar();
    fdsB = criar();
    struct pessoas dados;
    strcpy(dados.nome, "Juju");
    int i;
    for(i = 0; i < 5; i++){
        dados.id = i;
        inserir(fds, dados);
        inserir(fdsB, dados);
    }

    printf("\n");
    imprimir(fds);
    printf("\n");
    imprimir(fdsB);

    return 0;
}