#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) { // "a" e "b" é um ponteiro para um valor inteiro
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// Implementação do Bubble Sort //logica explicada no slide da aula
void bubbleSort(int V[], int n) {
    int i;
    int j;
    for(i = 0; i<= n - 1; i++ ){
        for(j = n-1; j >= i+1; j--){
            if(V[j] < V[j-1]){
                trocar(&V[j], &V[j-1]);
            }
        }
    }
}

// Função auxiliar para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    int i;
    for(i = 0; i<tamanho; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// Função principal para teste
int main() {
    // Exemplo de teste
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array original: ");
    imprimirArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Array ordenado: ");
    imprimirArray(arr, n);
    
    // Teste adicional com outro array
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\nSegundo teste:\n");
    printf("Array original: ");
    imprimirArray(arr2, n2);
    
    bubbleSort(arr2, n2);
    
    printf("Array ordenado: ");
    imprimirArray(arr2, n2);
    
    return 0;
}