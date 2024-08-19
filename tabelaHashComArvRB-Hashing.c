#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct NodeVP NodeVP;

struct NodeVP {
    int key;
    int color;
    NodeVP *father;
    NodeVP *left;
    NodeVP *right;
};

typedef struct HashT {
    int tam;
    NodeVP **buckets;
} HashT;

void rotacionar_esq(NodeVP **raiz, NodeVP *x) {
    NodeVP *y = x->right;
    x->right = y->left;
    if (y->left != NULL) 
        y->left->father = x;
    y->father = x->father;
    if (x->father == NULL) 
        *raiz = y;
    else if (x == x->father->left) 
        x->father->left = y;
    else 
        x->father->right = y;
    y->left = x;
    x->father = y;
}

void rotacionar_dir(NodeVP **raiz, NodeVP *y) {
    NodeVP *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->father = y;
    x->father = y->father;
    if (y->father == NULL) 
        *raiz = x;
    else if (y == y->father->left) 
        y->father->left = x;
    else 
        y->father->right = x;
    x->right = y;
    y->father = x;
}

void balancear(NodeVP **raiz, NodeVP *x) {
    while (x->father != NULL && x->father->color == 0) {
        if (x->father == x->father->father->left) {
            NodeVP *y = x->father->father->right;
            if (y != NULL && y->color == 0) {
                x->father->color = 1;
                y->color = 1;
                x->father->father->color = 0;
                x = x->father->father;
            } 
            else {
                if (x == x->father->right) {
                    x = x->father;
                    rotacionar_esq(raiz, x);
                }
                x->father->color = 1;
                x->father->father->color = 0;
                rotacionar_dir(raiz, x->father->father);
            }
        } 
        else {
            NodeVP *y = x->father->father->left;
            if (y != NULL && y->color == 0) {
                x->father->color = 1;
                y->color = 1;
                x->father->father->color = 0;
                x = x->father->father;
            } else {
                if (x == x->father->left) {
                    x = x->father;
                    rotacionar_dir(raiz, x);
                }
                x->father->color = 1;
                x->father->father->color = 0;
                rotacionar_esq(raiz, x->father->father);
            }
        }
    }
    (*raiz)->color = 1;
}

void inserir(NodeVP **raiz, int key) {
    NodeVP *aux = (NodeVP *)malloc(sizeof(NodeVP));
    aux->key = key;
    aux->left = aux->right = aux->father = NULL;
    aux->color = 0; 
    
    NodeVP *y = NULL;
    NodeVP *x = *raiz;
    
    while (x != NULL) {
        y = x;
        if (aux->key < x->key) x = x->left;
        else x = x->right;
    }
    
    aux->father = y;
    if (y == NULL) *raiz = aux;
    else if (aux->key < y->key) y->left = aux;
    else y->right = aux;
    
    balancear(raiz, aux);
}

int hashing_mult(int key, int B, float c) {
    float aux = key * c;
    return (int)(B * (aux - (int)aux));
}

HashT *criar(int tam) {
    HashT *t = (HashT *)malloc(sizeof(HashT));
    t->tam = tam;
    t->buckets = (NodeVP **)malloc(tam * sizeof(NodeVP *));
    for (int i = 0; i < tam; i++) {
        t->buckets[i] = NULL;
    }
    return t;
}

void inserir_tabela(int key, HashT *t, float c) {
    int aux = hashing_mult(key, t->tam, c);
    inserir(&(t->buckets[aux]), key);
}

void preOrder(NodeVP *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->key);
        preOrder(raiz->left);
        preOrder(raiz->right);
    }
}

void imprimir_tabela(HashT *t) {
    for (int i = 0; i < t->tam; i++) {
        printf("%d: ", i);
        if (t->buckets[i] == NULL) printf("-\n");
        else {
            preOrder(t->buckets[i]);
            printf("\n");
        }
    }
}


int main() {
    float c;
    int i, n, qtd;

    scanf("%f %d", &c, &n);
    scanf("%d", &qtd);
    
    int chaves[qtd];
    for (i=0; i<qtd; i++) 
    {
        scanf("%d", &chaves[i]);
    }

    HashT *tabela = criar(n);

    for (i=0; i<qtd; i++) 
    {
        inserir_tabela(chaves[i], tabela, c);
    }

    imprimir_tabela(tabela);

    return 0;
}