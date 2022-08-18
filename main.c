// hello.c
#include <stdio.h>
#include <pthread.h>

void func_hola_mundo(void){
    printf("Hola Mundo!");
}

void func_hello_world(void){
    printf("Hello World!");
}

void func_oi_mundo(void){
    printf("Oi Mundo");
}
 

int main(void)
{
    func_hello_world();
    func_oi_mundo();
    func_hola_mundo();

    return 0;
}
