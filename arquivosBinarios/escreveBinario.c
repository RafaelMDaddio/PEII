#include <stdio.h>

int main(int argc, char *argv[]){

    if(argc == 2){
        FILE *fb;
        fb = fopen(argv[1],"wb");

        if(fb == NULL){
            printf("Erro ao abrir arquivo.\n");
            return 0;
        }

        int v[10] = {0,1,2,3,4,5,6,7,8,9};
        
        int nW = fwrite(v,sizeof(int),10,fb);
        printf("Form escritos %d inteiros.\n", nW);
        if(nW != 10){
            printf("Erro na escrita!\n");
        }

        fclose(fb);        
    }
}