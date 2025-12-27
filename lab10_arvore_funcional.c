#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice {
    int valor;
    struct Vertice* esq;
    struct Vertice* dir;
    struct Vertice* pai;
} Vertice;

typedef struct Arvore {
    Vertice* raiz;
    int qtde;
} Arvore;

void in_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

Vertice *cria_vertice(int valor) {
    Vertice* novo = malloc(sizeof(Vertice));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = NULL;
    return novo;
}

Arvore *cria_arvore() {
    Arvore* arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    arvore->qtde = 0;
    return arvore;
}

Vertice* add(Vertice* raiz, int valor, Vertice* pai) {
    if (raiz == NULL) {
        Vertice* novo = cria_vertice(valor);
        novo->pai = pai;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esq = add(raiz->esq, valor, raiz);
    } else if (valor > raiz->valor) {
        raiz->dir = add(raiz->dir, valor, raiz);
    }

    return raiz;
}

void inserir(Arvore* arvore, int valor) {
    arvore->raiz = add(arvore->raiz, valor, NULL);
    arvore->qtde++;
}

Vertice *buscar_valor(Arvore* arvore, int valor) {
    Vertice* atual = arvore->raiz;
    while (atual != NULL) {
        if (valor < atual->valor) {
            atual = atual->esq;
        } else if (valor > atual->valor) {
            atual = atual->dir;
        } else {
            return atual;
        }
    }
    return NULL;
}

Vertice* maior_esq(Vertice* no) {
    Vertice* atual = no->esq;
    while (atual->dir != NULL) {
        atual = atual->dir;
    }
    return atual;
}

int remover_vertice(Arvore* arvore, Vertice* vertice) {
    if (vertice == NULL) return 0;

    // Caso 1: sem filhos
    if (vertice->esq == NULL && vertice->dir == NULL) {
        if (vertice->pai == NULL) {
            arvore->raiz = NULL;
        } else if (vertice->pai->esq == vertice) {
            vertice->pai->esq = NULL;
        } else {
            vertice->pai->dir = NULL;
        }
        free(vertice);
    }

    // Caso 2: apenas um filho
    else if (vertice->esq == NULL || vertice->dir == NULL) {
        Vertice* filho = (vertice->esq != NULL) ? vertice->esq : vertice->dir;
        if (vertice->pai == NULL) {
            arvore->raiz = filho;
            filho->pai = NULL;
        } else if (vertice->pai->esq == vertice) {
            vertice->pai->esq = filho;
            filho->pai = vertice->pai;
        } else {
            vertice->pai->dir = filho;
            filho->pai = vertice->pai;
        }
        free(vertice);
    }

    // Caso 3: dois filhos
    else {
        Vertice* substituto = maior_esq(vertice);
        vertice->valor = substituto->valor;
        remover_vertice(arvore, substituto);
        return 1;
    }

    arvore->qtde--;
    return 1;
}

int main(void) {
    int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
    Arvore *arvore = cria_arvore();

    for (int i = 0; i < 10; i++) {
        inserir(arvore, dados[i]);
        printf("Inseriu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        Vertice *vertice = buscar_valor(arvore, dados[i]);
        if (vertice != NULL) {
            remover_vertice(arvore, vertice);
        }
        printf("Removeu %d mostra em ordem -> ", dados[i]);
        in_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
        pre_ordem(arvore->raiz);
        printf("\n");
        printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
        pos_ordem(arvore->raiz);
        printf("\n");
    }

    free(arvore);
    return 0;
}