#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int possibilidades_troco(int t, int n, int vet[]) {
    int tab[t + 1];
    int i, j;
    tab[0] = 1;

    for (i=1; i<=t; i++)
    {
        tab[i] = 0;
    }

    for (j=0; j<n; j++)
    {
        for (i=vet[j]; i<=t; i++)
        {
            tab[i] += tab[i - vet[j]];
        }
    }

    return tab[t];
}

int main() {
    int t, n, i;
    scanf("%d", &t);
    scanf("%d", &n);

    int moedas[n];
    
    for (i=0; i<n; i++)
    {
        scanf("%d", &moedas[i]);
    }

    int result = possibilidades_troco(t, n, moedas);
    printf("%d\n", result);

    return 0;
}
