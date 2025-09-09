#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
	struct Celula *anterior;
	struct Celula *proximo;
	int valor;
}Celula;

typedef struct LDDE{
	Celula *primeiro;
	int qtde;
}LDDE;

LDDE *inicializa_lista(){
	LDDE *lista = malloc(sizeof(LDDE));
	lista->primeiro = NULL;
	lista->qtde = 0;
	return lista;
}

Celula *inicializa_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->anterior = NULL;
	celula->proximo = NULL;
	celula->valor = valor;
	return celula;
}

void inserir(LDDE *lista, int valor){
	Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    nova->anterior = NULL;

    /* ponteiros auxiliares */
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;

    while (atual != NULL && atual->valor <= valor){
        anterior = atual; //anterior avança 1
        atual = atual->proximo;
    }    

    if(atual == NULL && anterior == NULL) {  /*LISTA VAZIA*/
            lista->primeiro = nova;
    }
    else if(atual == NULL && anterior != NULL){ /*FIM DA LISTA*/
        anterior->proximo = nova;
        nova->anterior = anterior;
    }
    else if(atual != NULL && anterior != NULL){  /*MEIO DA LISTA*/
        anterior->proximo = nova;
        nova->proximo = atual;
        nova->anterior = anterior;
        atual->anterior = nova;
    }
    else if(atual != NULL && anterior == NULL){ /*INICIO DA LISTA*/
        lista->primeiro = nova;  
        nova->proximo = atual;
        atual->anterior = nova;
    } 
    
    lista->qtde++;
}
void imprimir_crescente(LDDE *lista){
    Celula *atual = lista->primeiro;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void imprimir_decrescente(LDDE *lista){
    Celula *atual = lista->primeiro;
    Celula *anterior = NULL;
    while(atual != NULL){
        anterior = atual; //anterior avança 1
        atual = atual->proximo;
    }
    while(anterior != NULL){
        printf("%d ", anterior->valor);
        anterior = anterior->anterior;
    }
    printf("\n");
}

Celula *buscar(LDDE *lista, int valor){
    Celula *atual = lista->primeiro;
	while (atual != NULL && atual->valor != valor){ //fica no while até o atual->valor == valor e retorna o atual(valor a ser buscado)
        atual = atual->proximo;
    }
	return atual;
}

void remover(LDDE *lista, int valor){
    Celula *atual = buscar(lista, valor); //como eu tenho o atual sendo a celula com o valor que quero remover posso fazer a logica de troca de ponteiros
    if(atual == NULL) {  /*LISTA VAZIA*/
            return;
    }
    else if(atual->proximo == NULL){ /*FIM DA LISTA*/
        if(atual->anterior != NULL){ //verifica se nao tem só essa celula na lista
            atual->anterior->proximo = NULL; 
        }else{
            lista->primeiro = NULL;

        }
    }
    else if(atual->proximo != NULL && atual->anterior != NULL){  /*MEIO DA LISTA*/
        atual->anterior->proximo = atual->proximo; //coloca o ponteiro da (celula anterior)->proximo na proxima celula (atual->proximo) 
        atual->proximo->anterior = atual->anterior; //coloca o ponteiro da (celula proxima)->anterior na celula anterior(atual->anterior)
    }
    else if(atual != NULL && atual->anterior == NULL){ /*INICIO DA LISTA*/
        lista->primeiro = atual->proximo; //aponta o começo da lista pra proxima celula
        if(atual->proximo != NULL){ 
            atual->proximo->anterior = NULL;
        }
    }
    free(atual); 
    lista->qtde--;
}

int main(void) {
  LDDE *lista = inicializa_lista();
	int in[] = {2, 3, 9, 6, 7, 4, 1, 8, 0, 5};
	int out[] = {0, 9, 1, 8, 5, 5, 6, 2, 3, 4, 7};
	int len_in = sizeof(in) / sizeof(int);
	int len_out = sizeof(out) / sizeof(int);
	for(int i = 0; i < len_in; i ++){
		inserir(lista, in[i]);
		imprimir_crescente(lista);
		imprimir_decrescente(lista);
	}
	for(int j = 0; j < len_out; j++){
		remover(lista, out[j]);
		imprimir_crescente(lista);
		imprimir_decrescente(lista);
	}
  return 0;
}