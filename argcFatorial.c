#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){
    if(x == 1){
        return 1;
    }
    return x*fatorial(x-1);
}

int main(int argc, char *argv[]){

    int x;

    if(argc != 2){
        printf("Erro no programa %s: tenho %d parametros, preciso de 2!", argv[0], argc);
        return 0;
    }

    x = atoi(argv[1]);
    printf("O fatorial de %d eh: %d\n", x, fatorial(x));

}
