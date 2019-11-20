#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    if(argc == 3){
        FILE *fp1;
        FILE *fp2;
        char c;

        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "w");

        if(fp1 == NULL || fp2 == NULL){
            printf("Erro para abrir arquivos!");
            return 0;
        }

        //leitura simples de caracteres
        while(!feof(fp1)){
           c = getc(fp1);
           if(!feof(fp1)){
               putc(c,fp2);
           }
        }

        fclose(fp1);
        fclose(fp2);
    }
}
