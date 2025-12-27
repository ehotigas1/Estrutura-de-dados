#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

typedef struct Arvore{
    No *raiz;
    int n;
}Arvore;

No *criaVertice(int valor){
    No *vertice = malloc(sizeof(No));
    vertice->esq = NULL;
    vertice->dir = NULL;
    vertice->valor = valor;
    return vertice;
}


void mostraInOrder(No *raiz){ //ERD
    if(raiz != NULL){
        mostraInOrder(raiz->esq);
        printf("%d\n",  raiz->valor);
        mostraInOrder(raiz->dir);
    }
}

void mostraPreOrder(No *raiz){ //RED
    if(raiz != NULL){
        printf("%d\n",  raiz->valor);
        mostraPreOrder(raiz->esq);
        mostraPreOrder(raiz->dir);
    }
}

void mostraPosOrder(No *raiz){ //EDR
    if(raiz != NULL){
        mostraPosOrder(raiz->esq);
        mostraPosOrder(raiz->dir);
        printf("%d\n",  raiz->valor);
    }
}

void mostraOutOrder(No *raiz){ //DRE 
    if(raiz != NULL){
        mostraOutOrder(raiz->dir);
        printf("%d\n",  raiz->valor);
        mostraOutOrder(raiz->esq);
        
    }
}

No *inserir(No *raiz,int valor){

    if(raiz == NULL){ //arvore vazia
        return criaVertice(valor);
    }
    if(valor < raiz->valor){
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if(valor > raiz->valor){
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}


void add(Arvore *t, int valor){  //feito para poder incrementar o n
    t->raiz = inserir(t->raiz,valor);
    t->n++;
}

int main(){
    printf("Arvore binaria\n");

    Arvore *t = malloc(sizeof(Arvore));
    t->raiz = NULL;
    t->n = 0;

    t->raiz = inserir(t->raiz, 5);
    t->raiz = inserir(t->raiz, 3);
    t->raiz = inserir(t->raiz, 7);
    t->raiz = inserir(t->raiz, 1);
    t->raiz = inserir(t->raiz, 8);
    t->raiz = inserir(t->raiz, 4);
    t->raiz = inserir(t->raiz, 6);
    t->raiz = inserir(t->raiz, 2);
    t->raiz = inserir(t->raiz, 9);
    mostraPreOrder(t->raiz);
    printf("\n");
    mostraInOrder(t->raiz);
    printf("\n");
    mostraPosOrder(t->raiz);
    printf("\n");
    mostraOutOrder(t->raiz);

    return 0;
}