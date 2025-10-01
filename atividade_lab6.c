#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
	int valor;
	struct Celula *proximo;
	struct Celula *anterior;
} Celula;

typedef struct {
	Celula *head;
	Celula *tail;
	int qtde;
} Queue;

Celula *cria_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->proximo = NULL;
	celula->anterior = NULL;
	celula->valor = valor;

	return celula;
}

Queue *cria_queue(){
	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->qtde = 0;

	return queue;
}

void enqueue(Queue *queue, int valor){
	Celula *nova = malloc(sizeof(Celula));
    nova->proximo = NULL;
    nova->anterior = NULL;
    nova->valor = valor;

    if(queue->qtde == 0){
        queue->head = nova;
        queue->tail = nova;
    }else{
        queue->tail->proximo = nova;
        nova->anterior = queue->tail;
        queue->tail  = nova;
    }
    queue->qtde++;
	}

int dequeue(Queue *queue){
	int valor = -1;
    if(queue->qtde == 0) return valor;
    
    if(queue-> qtde == 1){
        valor = queue->head->valor;
        free(queue->head);
        queue->head  = NULL;
        queue->tail = NULL;
    }else{
        valor = queue->head->valor;
        queue->head = queue->head->proximo;
        free(queue->head->anterior);
        queue->head->anterior = NULL;
    }
    queue->qtde--;
    return valor;
}

void show(Queue *queue){
    Celula *atual = queue->head;

    while(atual != NULL){
        printf("%d", atual->valor);
        atual = atual->proximo;
    }
}

void show_invertido(Queue *queue){
    Celula *atual = queue->tail;

    while(atual != NULL){
        printf("%d", atual->valor);
        atual = atual->anterior;
    }
}

int main(void) {
	Queue *qnum1 = cria_queue();
	Queue *qnum2 = cria_queue();
	Queue *res = cria_queue();
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
		}

    Celula *atual1 = qnum1->tail;
    Celula *atual2 = qnum2->tail;
    int add = 0;

    while(atual1 != NULL && atual2 != NULL){
        int valor1 = atual1->valor;
        atual1 = atual1->anterior;
        int valor2 = atual2->valor;
        atual2 = atual2->anterior;
        int soma = valor1 + valor2 + add;
        if (soma>=10){
            add = 1;
            int resposta = (soma) - 10;
            enqueue(res, resposta);
        }else{
            add = 0;
            enqueue(res, (soma));
        }
    
    }
    if (add == 1){
        enqueue(res, 1);
    }
    show_invertido(res);
	// implementar
}