#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell Cell;
typedef struct PilhaE PilhaE;

struct Cell {
    char item;
    Cell *next;
};

struct PilhaE {
    Cell *topo;
};

Cell* criar_celula(char key) {
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;
    c->next = NULL;
    return c;
}

PilhaE* criar_pilhaE() {
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));
    p->topo = NULL;
    return p;
}

int pilhaE_vazia(PilhaE *p) {
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(char key, PilhaE *p) {
    if (p == NULL)
        p = criar_pilhaE();

    Cell *aux = criar_celula(key);
    aux->next = p->topo;
    p->topo = aux;
}

char desempilhar(PilhaE *p) {
    if (!pilhaE_vazia(p)) {
        Cell *aux = p->topo;
        char item = aux->item;
        p->topo = aux->next;
        free(aux);
        return item;
    }
    return '\0';
}

int verifica_parenteses(const char *exp) {
    PilhaE *pilha = criar_pilhaE();
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            empilhar('(', pilha);
        }
        else if (exp[i] == ')')
        {
            if (desempilhar(pilha) != '(')
            {
                return 0;
            }
        }
    }
    if (!pilhaE_vazia(pilha)) 
    {
        return 0;
    }

    return 1;
}

int main() {
    int i, n;
    char exp[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", exp);
        if (verifica_parenteses(exp)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}