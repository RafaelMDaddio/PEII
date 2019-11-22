#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){


    if(argc == 2){
        FILE *fb;
        fb = fopen(argv[1],"r+b");

        if(fb == NULL){
            printf("Erro ao abrir arquivo.");
            return 0;
        }
        int v[20], i,j=1;
        int nR = fread(v,sizeof(int),20,fb);
        printf("Foram lidos %d inteiros\n", nR);

        //escreve numeros impares
        for(i=nR; i < 20;i++){            
            v[i] = j;
            j+=2;
        }

        int nW = fwrite(&v[nR],sizeof(int),10,fb);
        printf("Escreveu mais %d inteiros",nW);

        fclose(fb);

    }

}