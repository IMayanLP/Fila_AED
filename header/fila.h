struct pessoas {
    int id;
    char nome[20];
};

typedef struct fila Fila;

Fila* criar(); // OK
int inserir(Fila*, struct pessoas); // OK
int tamanho(Fila*); // OK
int imprimir(Fila*); // OK
int remover(Fila*); // OK
int acessar(Fila*, struct pessoas *); // OK
void destruir(Fila*); // OK

// FUNCOES ATIVIDADE

int inverter(Fila*); // OK
int limpezaC(Fila*); // OK
int limpezaE(Fila*); // OK
int ordenada(Fila*); // OK
int mover(Fila*, Fila*); // OK