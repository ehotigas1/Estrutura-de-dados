#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{ // essa struct referencia a si mesma, por isso tem Celula no inicio e fim da definicao da struct
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct{
    int qtde;
    Celula *primeira;
} Lista;


Lista *inicializa(){
    Lista *lista = malloc(sizeof(Lista));
    lista->qtde = 0;
    lista->primeira = NULL;
    return lista;

}

void imprimir(Lista *lista){
    printf("[ ");
    Celula *atual = lista->primeira;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;

    }

    printf("] -> qtde: %d", lista->qtde);
}

void inserir(Lista *lista, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;

    Celula *atual = lista->primeira;
    Celula *anterior = NULL;

    while(atual != NULL && atual->valor <= valor){
        anterior = atual;
        atual = atual->proximo;
    }

    if(atual == NULL && anterior == NULL){ //lista vazia
        lista->primeira = nova;
    }
    if(atual == NULL && anterior != NULL){ //final da lista
        anterior->proximo = nova;
    }
    if(atual != NULL && anterior != NULL){ //meio da lista
        anterior->proximo = nova;
        nova->proximo = atual;
    }
    if(atual != NULL && anterior == NULL){ //começo da lista
        nova->proximo = atual;
        lista->primeira = nova;
    }

    lista->qtde++;
}



int main(){
    Lista *lista = inicializa();
    printf("Lista dinâmica encadeada:\n");
    inserir(lista,2);
    inserir(lista,10);
    inserir(lista,7);
    inserir(lista,18);
    inserir(lista,1);
    inserir(lista,10);
    imprimir(lista);
    return 0;
}

