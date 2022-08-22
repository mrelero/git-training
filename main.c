// hello.c
#include <stdio.h>
#include <pthread.h>


enum idiomas_enum{
    PORTUGUES = 1,
    INGLES,
    ESPANHOL,
    ALEMAO,
};

///Clienter quer um Hello World Estilizado
void func_hello_world_new(void){
    printf("Hello World!\n) ");
}

void func_hallo_welt(void){
    printf("Hallo Welt!\n");
}

void func_hola_mundo(void){
    printf("Hola Mundo!\n");
}

void func_hello_world(void){
    printf("Hello World!\n");
}

void func_oi_mundo(void){
    printf("Oi Mundo!\n");
}

void func_selam_dunya(void){
    printf("Selam Dünya!\n");
}

void func_1(void){
    printf("1!");
}

void func_2(void){
    printf("2!");
}

void func_3(void){
    printf("3!");
}

void func_4(void){
    printf("4!");
}

void func_5(void){
    printf("5!");
}

void func_6(void){
    printf("6!");
}

void func_greatings(enum idiomas_enum idioma){
    switch (idioma)
    {
    case PORTUGUES:
        printf("Oi Mundo! \n");
        break;
    
    case INGLES:
        printf("Hello World! \n");
        break;
    
    case ESPANHOL:
        printf("Hola Mundo! \n");
        break;
    
    case ALEMAO:
        printf("Hola Mundo! \n");
        break;

    default:
        printf("Language selected is not valid, please insert a valide one! \n");
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
    func_hallo_welt();
    func_greatings(ALEMAO);

    return 0;
}
