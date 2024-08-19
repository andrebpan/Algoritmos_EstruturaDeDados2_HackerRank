#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b){
    return (a>b) ? a : b;
}

int soma_sub_max(int n, int vet[]) {
    int tab[n]; //tabela para armazenar as somas das subsquencias.
    int i;
    tab[0] = vet[0]; 

    
    for (i=1; i<n; i++) 
    {
        tab[i] = max(tab[i-1] + vet[i], vet[i]);
    }

    int soma_max = tab[0];
    for (i=1; i<n; i++) 
    {
        if (tab[i] > soma_max)
        {
            soma_max = tab[i];
        }
    }

    return soma_max;
}

int main() {
    int n, i;
    scanf("%d", &n);

    int vet[n];
    
    for (i=0; i<n; i++) 
    {
        scanf("%d", &vet[i]);
    }

    int result = soma_sub_max(n, vet);
    printf("%d", result);

    return 0;
}
