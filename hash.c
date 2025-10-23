#include <stdio.h>
#include <stdlib.h>

#define hash_size 7

typedef struct Celula{
    struct Celula *proximo;
    int valor;
}Celula;

typedef struct{
    Celula *inicio;
    int qtde;

}Lista;

typedef struct{
    Lista *table[hash_size];  //tabela hash
}Hash;


void imprimir(Hash *hash){
    Celula *atual;
    int i;
    for(i = 0; i < hash_size; i++){
        atual = hash->table[i]->inicio;
        while (atual != NULL){
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void inserir(Hash *hash, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    
    int pos = valor % hash_size;  //funcao que transforma o dado em uma posicao
    Lista *aux = hash->table[pos];
    nova->proximo = aux->inicio;
    aux->inicio = nova;
    aux->qtde++;

}

int buscas(Hash *hash, int valor){

    
    return 0;
}

int main(){
    Hash *hash = malloc(sizeof(Hash));
    for(int i = 0; i < hash_size; i++){
        Lista *lista = malloc (sizeof(Lista));
        lista->inicio = NULL;
        lista->qtde = 0;
        hash->table[i] = lista;
    }
    printf("hash\n");

    inserir(hash, 190);
    inserir(hash, 322);
    inserir(hash, 172);
    inserir(hash, 89);
    inserir(hash, 13);
    inserir(hash, 4);
    inserir(hash, 769);
    inserir(hash, 61);
    inserir(hash, 15);
    inserir(hash, 76);
    imprimir(hash);
    return 0;
}