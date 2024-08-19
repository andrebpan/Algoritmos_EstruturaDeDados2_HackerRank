#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct {
    int chave;
} Item;

struct Cell {
    Item item;
    Cell *prox;
};

typedef struct {
    int quantidade;
    Cell **celulas;
} HashT;

HashT *cria_tabela(unsigned int tam) {
    int i;
    HashT *h = (HashT*) malloc(sizeof(HashT));
    h->quantidade = tam;
    h->celulas = (Cell**) malloc(tam * sizeof(Cell*));

    for(i=0; i<tam; i++)
        h->celulas[i] = NULL;

    return h;
}

int hashing_div(int k, int B) {
    return k % B;
}

void inserir_listaE(HashT *h, int k, int B) {
    int pos = hashing_div(k, B);

    Item item;
    item.chave = k;
    Cell *novo = (Cell*) malloc(sizeof(Cell));
    novo->item = item;
    novo->prox = NULL;

    Cell *atual = h->celulas[pos];
    Cell *anterior = NULL;

    while(atual != NULL && atual->item.chave > k)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL)
    {
        novo->prox = h->celulas[pos];
        h->celulas[pos] = novo;
    } 
    else
    {
        anterior->prox = novo;
        novo->prox = atual;
    }
}

void imprimir(HashT *t, int num[], int qtd) {
    int i;
    //imprimir posicoes das chaves
    for(i=0; i<qtd; i++)
    {
        int pos = hashing_div(num[i], t->quantidade);
        printf("%d\n", pos);
    }
    printf("\n");
    
    //imprimir tabela hash
    for(i=0; i<t->quantidade; i++)
    {
        printf("%d: ", i);
        Cell *aux = t->celulas[i];
        if(aux == NULL) 
        {
            printf("-> -\n");
        } 
        else 
        {
            while(aux != NULL)
            {
                printf("-> %d ", aux->item.chave);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}

int main() {
    int tam, qtd;
    int i;
    scanf("%d", &tam);
    scanf("%d", &qtd);

    int num[qtd];
    HashT *h = cria_tabela(tam);

    for(i=0; i<qtd; i++)
    {
        scanf("%d", &num[i]);
        inserir_listaE(h, num[i], tam);
    }

    imprimir(h, num, qtd);

    return 0;
}