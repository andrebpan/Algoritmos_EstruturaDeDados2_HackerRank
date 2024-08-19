#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int manhattan(int* vet1, int* vet2, int ini, int fim){
    if(ini > fim)
    {
        return 0;
    }
    if(ini == fim)
    {
        return abs(vet1[ini] - vet2[ini]);
    }
    
    int div = (ini + fim) / 2;
    int esq = manhattan(vet1, vet2, ini, div);
    int dir = manhattan(vet1, vet2, div+1, fim);
    
    return esq + dir;
}


int main() {

    int n, i;
    scanf("%d",&n);
    
    int vet1[n];
    int vet2[n];
    
    for(i=0; i<n; i++)
    {
        scanf("%d",&vet1[i]);
    }
    
    for(i=0; i<n; i++)
    {
        scanf("%d",&vet2[i]);
    }
    
    int result = manhattan(vet1, vet2, 0, n-1);
    printf("%d",result);
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}