#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/fila.h"

struct elemento {
    struct pessoas dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

struct fila {
    struct elemento *inicio;
    struct elemento *fim;
};

Fila* criar(){
    Fila *fds;
    fds = (Fila*)malloc(sizeof(Fila));
    if(fds != NULL){
        fds->fim = NULL;
        fds->inicio = NULL;
    }
    return fds;
}

int inserir(Fila* fds, struct pessoas dados){
    if(fds == NULL) return 0;
    Elemento *novo = (Elemento*)malloc(sizeof(Elemento));
    novo->dados = dados;
    if(fds->fim == NULL && fds->inicio == NULL){
        fds->inicio = novo;
        fds->fim = novo;
        novo->prox = NULL;
    } else {
        fds->fim->prox = novo;
        fds->fim = novo;
        novo->prox = NULL;
    }
    return 1;
}

int tamanho(Fila* fds){
    if(fds == NULL) return -1;
    int count = 0;
    if(fds->fim == NULL && fds->inicio == NULL){
        return 0;
    }
    Elemento* aux = fds->inicio;
    while(aux != NULL){
        aux = aux->prox;
        count++;
    }
    return count;
}

int remover(Fila *fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) == 0) return 0;
    else if(tamanho(fds) == 1) {
        Elemento *aux = fds->inicio;
        fds->inicio = NULL;
        fds->fim = NULL;
        free(aux);
    } else {
        Elemento *aux = fds->inicio;
        fds->inicio = aux->prox;
        free(aux);
    }
    return 1;
}

int imprimir(Fila* fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) == 0) return 0;
    Elemento *aux = fds->inicio;
    while (aux != NULL){
        printf("[%d, %s]->", aux->dados.id, aux->dados.nome);
        aux = aux->prox;
    }
    printf("||");
    return 1;
}

void destruir(Fila *fds){
    if(fds == NULL) return 0;
    Elemento *aux = fds->inicio;
    while (tamanho(fds) != 0){
        remover(fds);
    }
    
    fds->inicio = NULL;
    fds->fim = NULL;

    return 1;
}

int acessar(Fila *fds, struct pessoas *dados){
    if(fds == NULL) return 0;
    if(tamanho(fds) == 0) return 0;
    else {
        *dados = fds->inicio->dados;
        return 1;
    }
}

// FUNCOES ATIVIDADE

int inverter(Fila *fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) < 2) return 0;
    else if(tamanho(fds) == 2){
        Elemento *aux, *ant;
        ant = fds->inicio;
        aux = fds->fim;
        aux->prox = aux;
        ant->prox = NULL;
        fds->inicio = aux;
        fds->fim = ant;
    } else {
        Elemento *ini, *aux, *ref, *fim;
        ini = fds->inicio;
        aux = fds->inicio;
        fim = fds->fim;
        ref = fds->fim;
        while(ref->prox != ini){
            while(aux->prox != ref){
                aux = aux->prox;
            }
            ref->prox = aux;
            ref = aux;
            aux = fds->inicio;
        }
        fds->inicio = fim;
        fds->fim = ini;
        ini->prox = NULL;
    }
}

int limpezaC(Fila *fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) < 3) return 0;
    Elemento *aux, *ant;
    ant = fds->inicio->prox;
    aux = ant->prox;
    while(aux != NULL){
        free(ant);
        fds->inicio->prox = aux;
        ant = aux;
        aux = aux->prox;
    }
    return 1;
}

int limpezaE(Fila *fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) < 3) return 0;
    else if(tamanho(fds) == 3) {
        Elemento *aux, *ant;
        ant = fds->inicio;
        aux = fds->fim;
        fds->inicio = ant->prox;
        fds->fim = ant->prox;
        fds->fim->prox = NULL;
        free(ant);
        free(aux);
    } else {
        Elemento *aux, *ant, *atual;
        ant = fds->inicio;
        aux = fds->fim;
        atual = fds->inicio;
        while(atual->prox != fds->fim){
            atual = atual->prox;
        }
        atual->prox = NULL;
        fds->inicio = ant->prox;
        fds->fim = atual;
        free(ant);
        free(aux);
    }

    return 1;
}

int ordenada(Fila *fds){
    if(fds == NULL) return 0;
    if(tamanho(fds) == 0) return 0;
    if(tamanho(fds) == 1) return 1;
    Elemento *aux;
    aux = fds->inicio;
    int bool = 1;
    while (aux->prox != NULL){
        if(aux->dados.id > aux->prox->dados.id){
            bool = 0;
        }
        aux = aux->prox;
    }
    return bool;
}

int mover(Fila *fdsA, Fila *fdsB){
    if(fdsA == NULL || fdsB == NULL) return 0;
    if(tamanho(fdsA) == 0) return 0;
    struct pessoas dados;
    acessar(fdsA, &dados);
    inserir(fdsB, dados);
    remover(fdsA);
}