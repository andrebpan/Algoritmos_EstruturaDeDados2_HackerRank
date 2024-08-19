#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell {
    char nome[20];
    Cell* next;
};

struct ListaE {
    Cell* head;
};

Cell* criar_celula(const char nome[]) {
    Cell* c = (Cell*)malloc(sizeof(Cell));
    strcpy(c->nome, nome);
    c->next = NULL;
    return c;
}

ListaE* criar_listaE() {
    ListaE* l = (ListaE*)malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

int listaE_vazia(ListaE* l) {
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(const char nome[], ListaE* l) {
    Cell* aux;
    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(nome);
    aux->next = l->head;
    l->head = aux;
}

void inserir_ultimo(const char nome[], ListaE* l) {
    Cell* aux, * novo;
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(nome, l);
    else {
        aux = l->head;
        while (aux->next != NULL)
            aux = aux->next;
        novo = criar_celula(nome);
        aux->next = novo;
    }
}

void imprimir(ListaE* l) {
    Cell* aux;
    if (!listaE_vazia(l)) {
        aux = l->head;
        while (aux != NULL) {
            printf("%s\n", aux->nome);
            aux = aux->next;
        }
    }
}

void ordenar_strings(ListaE* l, int n) {
    if (listaE_vazia(l) || n <= 1)
        return;

    Cell* atual;
    Cell* prox;

    for (int i = 0; i < n - 1; i++) {
        atual = l->head;
        prox = l->head->next;

        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(atual->nome, prox->nome) > 0) {
                char temp[20];
                strcpy(temp, atual->nome);
                strcpy(atual->nome, prox->nome);
                strcpy(prox->nome, temp);
            }

            atual = prox;
            prox = prox->next;
        }
    }
}

int main() {
    int i, n;
    char nome[20];
    ListaE* l = criar_listaE();

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", nome);
        inserir_ultimo(nome, l);
    }

    ordenar_strings(l,n);
    imprimir(l);

    return 0;
}