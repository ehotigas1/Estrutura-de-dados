#include <stdio.h>

#define SIZE 11

typedef struct{

    char data[SIZE];
    int head;
    int tail;
    int qtde;
} Fila;

void inicializa(Fila *fila){
    fila->head = 0;
    fila->tail = 0;
    fila->qtde = 0;
}
void imprimir(Fila *fila){
    printf("[ ");
    for(int i = fila->head; i != fila->tail; i = (i+1)%SIZE){
        printf("%c ", fila->data[i]);
    }
    printf("]\n");
}

int isEmpty(Fila *fila){
    return fila->head == fila->tail;
}
int isFull(Fila *fila){
    return (fila->tail + 1) % SIZE == fila->head; 
}
void enfileirar(Fila *fila, char valor){
    if(isFull(fila)) return;
    fila->data[fila->tail] = valor;
    fila->tail = (fila->tail + 1) % SIZE;
    fila->qtde++;

}
int desenfileirar(Fila *fila){  //todo char é um int
    if(isEmpty(fila)) return -1;
    char data = fila->data[fila->head];
    fila->head = (fila->head + 1) % SIZE;
    fila->qtde--;
    return data;
}
int main(){
    printf("fila estatica\n");
    Fila fila;
    inicializa(&fila);
    enfileirar(&fila, 'a');
    enfileirar(&fila, 'b');
    enfileirar(&fila, 'c');
    enfileirar(&fila, 'd');
    desenfileirar(&fila);
    desenfileirar(&fila);
    enfileirar(&fila, 'e');
    imprimir(&fila);
    return 0;
}
