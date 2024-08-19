#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void fracao_egipcia(int n, int d) {
    if (d == 0 || n == 0)
    {
        return;
    }
    
    if (d % n == 0)
    {
        printf("1/%d\n", d / n);
        return;
    }
    
    if (n % d == 0)
    {
        printf("%d\n", n / d);
        return;
    }
    
    if (d > n)
    {
        int prox_d = d / n + 1;
        printf("1/%d + ", prox_d);
        fracao_egipcia(n * prox_d - d, d * prox_d);
    }
    else
    {
        printf("%d + ", n / d);
        fracao_egipcia(n % d, d);
    }
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    
    fracao_egipcia(n, d);
    
    return 0;
}