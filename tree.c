#include<stdio.h>
#include<stdlib.h>

typedef struct Celula {
    int valor;
    struct Celula *esq;
    struct Celula *dir;
} Celula;

typedef struct Tree {
    Celula *raiz;
    int qtde;
} Tree;

void inserir(Tree *arvore, int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->valor = valor;

    if(arvore->raiz == NULL){
        arvore->raiz = nova;
    } else{
        Celula *atual = arvore->raiz;
        Celula *anterior = NULL;
        while(atual != NULL){
            anterior = atual;
            if(atual->valor > valor){
                atual = atual->esq;
            } else{
                atual = atual->dir;
            }
        }
        if(anterior->valor > valor){
            anterior->esq = nova;
        } else{
            anterior->dir = nova;
        }
    }
    arvore->qtde++;
}

int main(){

    Tree *arvore = malloc(sizeof(Tree));
    arvore->qtde = 0;
    int dados[] = {13, 5, 18, 4, 8, 15, 21, 2, 16};

    for(int i = 0; i<9; i++){
        inserir(arvore, dados[i]);
    }
    return 0;
}