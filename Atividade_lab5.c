#include <stdio.h>

#define LEN 100

typedef struct {
	char data[LEN];
	int head;
	int tail;
	int qtde;
} Queue;

int isEmpty(Queue *queue){
    return queue->head == queue->tail;
}
int isFull(Queue *queue){
    return (queue->tail + 1) % LEN == queue->head; 
}

void enqueue(Queue *queue, char caracter) {
    if(isFull(queue)) return;
    queue->data[queue->tail] = caracter;
    queue->tail = (queue->tail + 1) % LEN;
    queue->qtde++;

}

int dequeue(Queue *queue) {
    if(isEmpty(queue)) return -1;
    char data = queue->data[queue->head];
    queue->head = (queue->head + 1) % LEN;
    queue->qtde--;
    return data;
}

void show(Queue *queue) {
    for(int i = queue->head; i != queue->tail; i = (i+1)%LEN){
        printf("%c", queue->data[i]);
    }
}

void start_queue(Queue *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->qtde = 0;
}

int main(void) {
    int flag = 1;
    char s[LEN];
    fgets(s, sizeof(s), stdin);
    Queue queue;
    Queue aux;
    start_queue(&queue);
    start_queue(&aux);

    for (int i = 0; s[i] != '\0'; i++) {
        enqueue(&queue, s[i]);
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char data = dequeue(&queue);
        if (data == '('){
            enqueue(&aux, s[i]);
        }
        else if (data == ')'){
            if(dequeue(&aux) == -1){
                flag = 0;
                break; //quebra o for
            }
        }
        show(&queue);
    }

    if(flag == 1 && isEmpty(&aux)){
        printf("correto");
    }
    else{
        printf("incorreto");
    }
    return 0;
}
