#include <stdio.h>


int main(){

    int a, *p = NULL; 

    scanf("%d", &a); 

    p = &a; 

    printf("%d \t %p \t %p \n", *p, p, &p); 

    return 0; 

} 