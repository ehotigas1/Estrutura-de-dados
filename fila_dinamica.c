#include <stdio.h>
#include <stdlib.h>


typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula *anterior;
}Celula;

typedef struct{
    int qtde;
    struct Celula *head;
    struct Celula *tail;
}Fila;


void imprimir(Fila *fila){

    printf("[ ");
    Celula *atual = fila->head;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf(" ] qtde: %d\n", fila->qtde);

}

Fila *inicializa(){
    Fila *fila = malloc(sizeof(Fila));
    fila->qtde = 0;
    fila->head = NULL;
    fila->tail = NULL;
    return fila;
}

void enfileirar(Fila *fila, int valor){

    Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->anterior = NULL;
    nova->valor = valor;

    if(fila->qtde == 0){
        fila->head = nova;
        fila->tail = nova;
    }else{
        fila->tail->proximo = nova;
        nova->anterior = fila->tail;
        fila->tail  = nova;
    }
    fila->qtde++;
}

int desenfileirar(Fila *fila){
    int valor = -1;
    if(fila->qtde == 0) return valor;
    
    if(fila-> qtde == 1){
        valor = fila->head->valor;
        free(fila->head);
        fila->head  = NULL;
        fila->tail = NULL;
    }else{
        valor = fila->head->valor;
        fila->head = fila->head->proximo;
        free(fila->head->anterior);
        fila->head->anterior = NULL;
    }
    fila->qtde--;
    return valor;
}


int main(){
    Fila *fila = inicializa();
    printf("Fila dinamica\n");
    imprimir(fila);
    enfileirar(fila, 10);
    enfileirar(fila, 12);
    enfileirar(fila, 20);
    imprimir(fila);
    desenfileirar(fila);
    imprimir(fila);
    return 0;
}