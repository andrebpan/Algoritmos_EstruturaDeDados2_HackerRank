#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Cell Cell;


typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};


struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f) {
    Cell *aux = criar_celula(key);
    if (f->inicio == NULL) {
        f->inicio = f->fim = aux;
    } else {
        f->fim->next = aux;
        f->fim = f->fim->next;
    }
}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

void inverter_fila(FilaE* f) {
    if (!filaE_vazia(f)) {
        int temp = desenfileirar(f);
        inverter_fila(f);
        enfileirar(temp, f);
    }
}

void concatenar_inverter(FilaE* f1, FilaE* f2, FilaE* f3) {
    inverter_fila(f1);
    inverter_fila(f2);

    while (!filaE_vazia(f1)) {
        enfileirar(desenfileirar(f1), f3);
    }

    while (!filaE_vazia(f2)) {
        enfileirar(desenfileirar(f2), f3);
    }
}


int main() {

    FilaE *f1 = criar_filaE(); 
    FilaE *f2 = criar_filaE();
    FilaE *f3 = criar_filaE();
    
    int n;
    
    do
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            enfileirar(n,f1);
        }
    }while(n!=-1);
    
    do
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            enfileirar(n,f2);
        }
    }while(n!=-1);

    concatenar_inverter(f1,f2,f3);
    imprimir(f3);
    
    return 0;
}