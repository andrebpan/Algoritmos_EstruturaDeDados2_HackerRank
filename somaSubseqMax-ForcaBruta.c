#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int soma_submax(int vet[], int n) {
    int soma_max = vet[0];
    int i, j;

    for (i=0; i<n; i++)
    {
        int soma_atual = 0;
        for (j=i; j<n; j++)
        {
            soma_atual += vet[j];
            if (soma_atual > soma_max)
            {
                soma_max = soma_atual;
            }
        }
    }
    return soma_max;
}

int main() {

    int n;
    scanf("%d",&n);
    int vet[n];
    int i;
    
    for(i=0; i<n; i++)
    {
        scanf("%d",&vet[i]);
    }
    
    int result = soma_submax(vet, n);
    printf("%d",result);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}