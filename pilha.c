#include<stdio.h>
#include<stdlib.h>

typedef struct Celula{
    char valor;
    struct Celula *proxima;
    struct Celula *anterior;

}Celula;

typedef struct{
    int qtde;
    struct Celula *topo;
}Pilha;

void imprimir(Pilha *pilha){
    printf("[ ");
    Celula *atual = pilha->topo;
    while(atual != NULL){
        printf("%c ", atual->valor);
        atual = atual->anterior;
    }
    printf("] qtde: %d\n", pilha->qtde);
}

void inserir(Pilha *pilha, char valor){
    Celula *nova = malloc(sizeof(Celula));
    nova->valor = valor;
    nova->anterior = NULL;
    nova->proxima = NULL;

    if (pilha->qtde > 0){
        nova->anterior = pilha->topo;
        pilha->topo->proxima = nova;
    }

    pilha->topo = nova;
    pilha->qtde++;
}

char remover(Pilha *pilha){
    char valor;
    if(pilha->qtde > 1){
        valor = pilha->topo->valor;
        pilha->topo = pilha->topo->anterior;
        free(pilha->topo->proxima);
        pilha->topo->proxima = NULL;
    }else if (pilha->qtde ==1){
        valor = pilha->topo->valor;
        free(pilha->topo);
        pilha->topo = NULL;
    }else{
        return '@';
    }
    pilha->qtde--;
    return valor;
}




int main(){
    printf("Pilha dinamica\n");

    Pilha *pilha = malloc(sizeof(pilha));
    pilha->qtde = 0;
    pilha->topo = NULL;
    /*
    inserir(pilha, 'a');
    inserir(pilha, 'b');
    inserir(pilha, 'c');
    inserir(pilha, 'd');
    remover(pilha);
    remover(pilha);
    remover(pilha);
    imprimir(pilha);
*/
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    for (int i = 0; expr[i] != '\n'; i++){
        printf("%c ", expr[i]);
    }
    int status;
    char retorno;  
    for(int i = 0; expr[i] != '\n'; i++ ){
        if(expr[i] == '('){
            inserir(pilha, '(');
        }
        else if(expr[i] == ')'){
            retorno = remover(pilha);
            if (retorno =='@')
            break;
        }
    }
    if(pilha->qtde == 0 && retorno != '@'){
        printf("Expressão correta");
    }else{
        printf("Expressão incorreta");
    }
    return 0;
}