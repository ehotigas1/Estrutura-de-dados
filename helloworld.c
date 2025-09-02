// Aula 1 teoria - lista 
#include <stdio.h>


#define LEN 10

typedef struct{
    int values[LEN];
    int n;
} list;

int is_full(list *l){
    return l->n == LEN;
}

int is_empty(list *l){
    return l->n == 0;
}

int get_idx(list *l, int value){
    int i = 0;
    while(i < l->n && value > l->values[i]){
        i++;
    }
    return i;
}

void move(list *l, int idx){
    int i;
    for(i = l->n; i > idx; i--){
        l->values[i] = l->values[i - 1];
    }
}

void show(list *l){
    int i;
    printf("[ ");
    for(i=0; i< l->n; i++){
        printf("%d ", l->values[i]);
    }
    printf("]\n");
}

void insert(list *l, int value){
    if(is_full(l)){
        return;
    }
    int idx = 0;
    if(!is_empty(l)){
        idx = get_idx(l, value);
        move(l,idx);
    }
    l->values[idx] = value;
    l->n++;
}


int main(){
    //printf("hello world!!");

    list l;
    l.n = 0;
    list *pl = &l;
    insert(pl, 8);
    insert(pl, 42);
    insert(pl, 9);
    insert(pl, 7);
    show(pl);



    return 0;
}