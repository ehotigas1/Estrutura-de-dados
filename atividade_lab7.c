#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
  struct Cell *anterior;
  struct Cell *proximo;
  char valor;
} Cell;

typedef struct {
  Cell *top;
  int qtde;
} Stack;

Cell *start_cell(char valor) {
  Cell *nova = malloc(sizeof(Cell));
  nova->anterior = NULL;
  nova->proximo = NULL;
  nova->valor = valor;
  return nova;
}

Stack *start_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->qtde = 0;
  stack->top = NULL;
  return stack;
}

void push(Stack *stack, char valor) {
  Cell *nova = start_cell(valor);
  if (stack->qtde != 0) {
    nova->proximo = stack->top;
    stack->top->anterior = nova;
  }
  stack->top = nova;
  stack->qtde++;
}

char pop(Stack *stack) {
  if (stack->qtde > 0) {
    char valor = stack->top->valor;
    Cell *top = stack->top;
    stack->top = stack->top->proximo;
    if (stack->top != NULL)
      stack->top->anterior = NULL;
    stack->qtde--;
    free(top);
    return valor;
  } else {
    return 'x';
  }
}

int is_opening(char c) {
  return (c == '{' || c == '[' || c == '(');
}

int is_closing(char c) {
  return (c == '}' || c == ']' || c == ')');
}

int matches(char open, char close) {
  if (open == '{' && close == '}') return 1;
  if (open == '[' && close == ']') return 1;
  if (open == '(' && close == ')') return 1;
  return 0;
}

int level(char c) {
    if (c == '{') return 1;
    if (c == '[') return 2;
    if (c == '(') return 3;
    return 0;
}

int main(void) {
    Stack *stack = start_stack();
  
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (is_opening(c)) {
            if (stack->qtde > 0) {
                int top_level = level(stack->top->valor);
                int current_level = level(c);
                if (current_level <= top_level) {
                    printf("incorreto\n");
                    return 0;
                }
            }
            push(stack, c);
        } else if (is_closing(c)) {
            if (stack->qtde == 0) {
                printf("incorreto\n");
                return 0;
            }
            char open = pop(stack);
            if (!matches(open, c)) {
                printf("incorreto\n");
                return 0;
            }
        }
    }

    if (stack->qtde == 0) {
        printf("correto\n");
    } else {
        printf("incorreto\n");
    }

    return 0;
}