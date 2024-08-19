#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int soma_max(int vet[], int n)
{
    int div_meio;
    int esq, dir;
    int aux;
    
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        if(vet[0] > 0)
        {
            return vet[0];
        }
        else
        {
            return 0;
        }
    }
    
    div_meio = n / 2;
    aux = n - div_meio;
    esq = soma_max(vet, div_meio);
    dir = soma_max(vet + div_meio, aux);
    
    return esq + dir;
}

int main() {

    int n, i;
    int result;
    
    scanf("%d",&n);
    int vet[n];
    
    for(i=0; i<n; i++)
    {
        scanf("%d",&vet[i]);
    }
    
    result = soma_max(vet, n);
    printf("%d",result);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}