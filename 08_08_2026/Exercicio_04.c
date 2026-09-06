#include <stdio.h>

int main (){

    int x = 0, y = 0, z = 0;
    int a = 0, b = 0;
   
    scanf("%d %d %d", &x, &y, &z);

   a = (x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z);
   b = x < y ? x < z ? x : z : y < z ? y : z;

    printf("Com parenteses: %d\n", a);
    printf("Sem parenteses: %d\n", b);

    return 0;
}