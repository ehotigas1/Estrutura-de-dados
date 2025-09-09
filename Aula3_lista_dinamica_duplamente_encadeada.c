#include <stdio.h>
#include <stdlib.h>


typedef struct Celula {
    int valor;
    struct Celula *proxima;
    struct Celula *anterior;

}Celula;

typedef struct {
    int qtde;
    Celula *primeira;

}LDDE;

void inserir(LDDE *lista, int dado){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = dado;
    nova->proxima = NULL;
    nova->anterior = NULL;

    /* ponteiros auxiliares */
    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while (atual != NULL && atual->valor <= dado){
        anterior = atual; //anterior avança 1
        atual = atual->proxima;
    }    

    if(atual == NULL && anterior == NULL) {  /*LISTA VAZIA*/
            lista->primeira = nova;
    }
    else if(atual == NULL && anterior != NULL){ /*FIM DA LISTA*/
        anterior->proxima = nova;
        nova->anterior = anterior;
    }
    else if(atual != NULL && anterior != NULL){  /*MEIO DA LISTA*/
        anterior->proxima = nova;
        nova->proxima = atual;
        nova->anterior = anterior;
        atual->anterior = nova;
    }
    else if(atual != NULL && anterior == NULL){ /*INICIO DA LISTA*/
        lista->primeira = nova;  
        nova->proxima = atual;
        atual->anterior = nova;
    } 
    
    lista->qtde++;
}

void imprimir (LDDE *lista){
    printf("[ ");
    Celula *atual = lista->primeira;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proxima;
    }
    printf("] qtde: %d\n", lista->qtde);

}

void imprimir_inverso(LDDE *lista){
    printf("[");
    Celula *atual = lista->primeira;
    Celula *anterior = NULL;
    while(atual != NULL){
        anterior = atual; //anterior avança 1
        atual = atual->proxima;
    }
    while(anterior != NULL){
        printf("%d ", anterior->valor);
        anterior = anterior->anterior;
    }
    printf("] qtde: %d\n", lista->qtde);
}



int main(){
    printf("Lista duplamente encadeada\n");
    LDDE *lista = malloc(sizeof(LDDE));
    lista-> qtde = 0;
    lista -> primeira = NULL;
    imprimir(lista); 
    inserir(lista,10);
    inserir(lista,20);
    inserir(lista,15);
    inserir(lista,50);
    inserir(lista,12);
    inserir(lista,0);
    inserir(lista,-12);
    imprimir(lista);
    imprimir_inverso(lista);
    return 0;
}