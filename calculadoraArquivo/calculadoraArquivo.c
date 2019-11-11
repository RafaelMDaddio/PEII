#include <stdio.h>
#include <stdlib.h>

float calcula(int a, int b, char op){
    float res=0;

    switch(op){
        case '+': res = a + b;
                break;
        case '-': res = a - b;
                break;
        case '*': res = a * b;
                break;
        case '/': if(b == 0){
                    printf("Deu ruim na divisao");
                    break;
                }
                res = a / b;
                break;
        default: printf("Deu ruim");
    }

    return res;
}

int main(int argc, char *argv[]){

    if(argc == 3){
        FILE *fp1;
        FILE *fp2;
        char op;
        int a, b;
        float res;

        fp1 = fopen(argv[1], "r");
        fp2 = fopen(argv[2], "w");

        if(fp1 == NULL || fp2 == NULL){
            printf("Erro para abrir arquivos!");
            return 0;
        }

        while(!feof(fp1)){
            int err = fscanf(fp1, "%d %c %d", &a, &op, &b);
            res = calcula(a,b,op);
            if(err != EOF){
               fprintf(fp2,"%.2f\n",res);
           }
        }

        fclose(fp1);
        fclose(fp2);
    }
}