// hello.c
#include <stdio.h>
#include <pthread.h>

void func_hello_world(void){
    printf("Hello World");
}
 
int main(void)
{
    func_hello_world();
    printf("Oi Mundo");

    return 0;
}
