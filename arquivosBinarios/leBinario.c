#include <stdio.h>

int main(int argc, char *argv[]){

    if(argc == 2){
        FILE *fb;
        fb = fopen(argv[1],"rb");

        if(fb == NULL){
            printf("Erro ao abrir arquivo.\n");
            return 0;
        }
        int v[10],i;
      
        int nR = fread(v,sizeof(int),10,fb);
        printf("Foram lidos %d inteiros.\n", nR);
        if(nR != 10){
            printf("Erro na leitura!\n");
        }

        for(i = 0; i < nR; i++){
            printf("%d\n",v[i]);
        }

        fclose(fb);
    }
}
