// hello.c
#include <stdio.h>
#include <pthread.h>


enum idiomas_enum{
    PORTUGUES = 1,
    INGLES,
    ESPANHOL,
};

void func_hallo_welt(void){
    printf("Hallo Welt!");
}

void func_hola_mundo(void){
    printf("Hola Mundo!");
}

void func_hello_world(void){
    printf("Hello World!");
}

void func_oi_mundo(void){
    printf("Oi Mundo!");
}
 
void func_greatings(enum idiomas_enum idioma){
    switch (idioma)
    {
    case PORTUGUES:
        printf("Oi Mundo\n");
        break;
    case INGLES:
        printf("Hello World! \n");
        break;
    case ESPANHOL:
        printf("Hola Mundo! \n");
        break;

    default:
        printf("Language selected is not valid \n");
        break;
    }
}


void func_oi(enum idiomas_enum idioma){
        switch (idioma)
    {
    case PORTUGUES:
        printf("Oi\n");
        break;
    case INGLES:
        printf("Hello! \n");
        break;
    case ESPANHOL:
        printf("Hola! \n");
        break;

    default:
        printf("Language selected is not valid \n");
        break;
    }
}

int main(void)
{
    func_hello_world();
    func_oi_mundo();
    func_hola_mundo();
    func_greatings(INGLES);
    func_greatings(PORTUGUES);
    func_greatings(ESPANHOL);
    func_oi(INGLES);
    

    return 0;
}
