#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int id; 
    int e;  
    int d;  
} Tarefa;

int compara(const void *a, const void *b) {
    Tarefa *tarefaA = (Tarefa *)a;
    Tarefa *tarefaB = (Tarefa *)b;
    return (tarefaB->d - tarefaB->e) - (tarefaA->d - tarefaA->e);
}

int sequenciamento(Tarefa tarefas[], int n) {
    qsort(tarefas, n, sizeof(Tarefa), compara);
    int i;
    int atraso = 0;
    int saldo_deadline = 0;
    int tempo_total = 0;
    
    for(i=0; i<n; i++)
    {
        saldo_deadline += tarefas[i].d;
        tempo_total += tarefas[i].e;
        int saldo_tempo = tarefas[i].d - tarefas[i].e;
        int posicao_inserir = i;
        
        while(posicao_inserir > 0 && saldo_tempo > (tarefas[i].d - tarefas[i].e))
        {
            tarefas[posicao_inserir].id = tarefas[posicao_inserir - 1].id;
            posicao_inserir--;
        }
        tarefas[posicao_inserir].id = tarefas[i].id;
    }

    atraso = saldo_deadline - tempo_total;
    if (atraso < 0) {
        atraso *= -1;
    } 
    else {
        atraso = 0;
    }

    for (i=0; i<n; i++) 
    {
        printf("%d ", tarefas[i].id);
    }
    
    return atraso;
}

int main() {
    int i, n;
    scanf("%d", &n);

    Tarefa tarefas[n];

    for (i=0; i<n; i++) 
    {
        tarefas[i].id = i;
        scanf("%d %d", &tarefas[i].e, &tarefas[i].d);
    }

    int result = sequenciamento(tarefas, n);
    printf("\n%d", result);

    return 0;
}