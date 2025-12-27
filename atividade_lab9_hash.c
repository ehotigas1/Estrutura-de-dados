#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
  int valor;
  struct Celula* proximo;
}Celula;

typedef struct {
  Celula* inicio;
}Lista;

typedef struct {
  Lista* table[tam_hash];
}Hash;

Hash* start_hash(){
  // implementar
  Hash *hash = malloc(sizeof(Hash));
    for(int i = 0; i < tam_hash; i++){
        Lista *lista = malloc (sizeof(Lista));
        lista->inicio = NULL;
        hash->table[i] = lista;
    }
    return hash;
}

void inserir_hash(Hash* hash, int valor){
  // implementar
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->proximo = NULL;
    
    int pos = valor % tam_hash;  //funcao que transforma o dado em uma posicao
    Lista *aux = hash->table[pos];
    nova->proximo = aux->inicio;
    aux->inicio = nova;
}

void remover_hash(Hash* hash, int valor){
  // implementar
    int pos = valor % tam_hash;  //funcao que transforma o dado em uma posicao
    Celula*atual = hash->table[pos]->inicio;
    Celula*anterior = NULL;
    while(atual != NULL && atual->valor != valor){
      anterior = atual;
      atual = atual->proximo;
    }
    if (atual == NULL) return; // Valor não encontrado

    if(atual == NULL && anterior == NULL){ //lista vazia
        return;
    }
    if(anterior != NULL){ //final da lista
        anterior->proximo = atual->proximo;
    }
    if(anterior != NULL){ //meio da lista
        anterior->proximo = atual->proximo;
    }
    if(atual != NULL && anterior == NULL){ //começo da lista
       hash->table[pos]->inicio = atual->proximo;
    }
    free(atual);
}

void imprimir(Hash* hash){
  printf("---------------------\n");
  // implementar
  Celula *atual;
    int i;
    for(i = 0; i < tam_hash; i++){
        printf("%d -> ", i);
        atual = hash->table[i]->inicio;
        while (atual != NULL){
            printf("%d ", atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}