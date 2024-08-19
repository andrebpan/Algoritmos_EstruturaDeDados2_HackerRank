#include <stdio.h>
#include <stdlib.h>

typedef struct CellDE CellDE;

typedef struct ListaDE ListaDE;

struct CellDE{
    int item; 
    CellDE *previous, *next;
};


struct ListaDE{
    CellDE *head;
};


CellDE* criar_celulaDE(int key){
    CellDE *c = (CellDE*) malloc(sizeof(CellDE));
    c->item = key;

    c->previous = c->next = NULL;

    return c;
}


ListaDE* criar_ListaDE(){
    ListaDE* l = (ListaDE*) malloc(sizeof(ListaDE));

    l->head = NULL;

    return l;
}


int ListaDE_vazia(ListaDE *l){
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, ListaDE *l){
    CellDE *aux; 

    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}


void inserir_primeiro(int key, ListaDE *l){
    CellDE *aux;
    
    if (l == NULL)
        l = criar_ListaDE();

    aux = criar_celulaDE(key);

    aux->next = l->head;
    
    if (l->head != NULL)
        l->head->previous = aux;

    l->head = aux;
}

void inserir_ultimo(int key, ListaDE *l){
    CellDE *aux, *nova; 

    if (l == NULL)
        l = criar_ListaDE();

    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        nova = criar_celulaDE(key);

        aux->next = nova;
        nova->previous = aux;
    }
}


void inserir_ordenado(int key, ListaDE *l){
    CellDE *auxA, *auxP, *nova;

    if (l == NULL)
        l = criar_ListaDE();

    if (ListaDE_vazia(l))
        inserir_primeiro(key, l);
    else{
        nova = criar_celulaDE(key);

        if (l->head == NULL)
            l->head = nova;
        else if (key < l->head->item){
            nova->next = l->head;
            l->head->previous = nova;
            l->head = nova;
        }else{
            auxP = auxA = l->head;

            while((auxA != NULL) && (key > auxA->item)){
                auxP = auxA;

                auxA = auxA->next;
            }
            
            auxP->next = nova;
            nova->previous = auxP;

            nova->next = auxA;

            if (auxA != NULL)
                auxA->previous = nova;
        }
    }
}


int remover(int key, ListaDE *l){
    CellDE *auxA;

    if (!ListaDE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
            l->head->previous = NULL;
            free(auxA);
            
            return 1;
        }else{
            while((auxA != NULL) && (auxA->item != key))
                auxA = auxA->next;
                
            if (auxA != NULL){
                auxA->previous->next = auxA->next;
                
                if (auxA->next != NULL)
                    auxA->next->previous = auxA->previous;
            }
            
            free(auxA);
            
            return 1;
        }
    }

    return 0;
}

void imprimir(ListaDE *l){
    CellDE *aux; 
            
    if (!ListaDE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

int liberar_LE(ListaDE *l){
    CellDE *aux = NULL;
               
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}


int tamanho_LE(ListaDE *l){
    CellDE *aux;
    int tam = 0;

     if (!ListaDE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}


void remover_repetidos(ListaDE* l)
{
    if (l == NULL || l->head == NULL)
        return;

    CellDE *atual = l->head;

    while (atual != NULL)
    {
        CellDE *aux = atual->next;
        while (aux != NULL) 
        {
            if (atual->item == aux->item)
            {
                CellDE *repetido = aux;
                aux = aux->next;
                if (repetido->previous != NULL)
                    repetido->previous->next = repetido->next;
                if (repetido->next != NULL)
                    repetido->next->previous = repetido->previous;
                free(repetido);
            } else {
                aux = aux->next;
            }
        }
        atual = atual->next;
    }
}


int main() {

    ListaDE *l1 = criar_ListaDE();
    int n;
    
    do
    {
        scanf("%d",&n);
        if(n!=-1)
        {
            inserir_ultimo(n,l1);
        }
    }while(n!=-1);
    
    remover_repetidos(l1);
    imprimir(l1);
    
    return 0;
}