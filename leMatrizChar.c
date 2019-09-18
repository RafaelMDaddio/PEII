#include<stdio.h>
#include<stdlib.h>

char **instancia_le_fgets(int tamLin, int tamCol){
    char **m;
    int i;

    //instanciando
    m = (char**) malloc(tamLin * sizeof(char *));
    for(i = 0; i < tamLin;i++){
        m[i] = (char *) malloc(tamCol * sizeof(char));
    }

    //lendo
    for(i=0;i<tamLin;i++){
        fgets(m[i], tamCol,stdin);
    }
    return m;
}

char **instancia_le_scanf(int tam){
    char **m, aux;
    int i,j;

    //instanciando
    m = (char**) malloc(tam * sizeof(char *));
    for(i = 0; i < tam;i++){
        m[i] = (char *) malloc(tam * sizeof(char));
    }

    //lendo
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){            
            do{             
                scanf("%c", &aux);
            }while((aux == '\n') || (aux == '\r'));
            m[i][j] = aux;
        }
    }
    return m;
}

void exibe_matriz(char **m, int tam){
    int i, j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf(" %c",m[i][j]);
        }
        printf("\n");
    }
}

void libera_matriz(char **m, int tam){
    int i;
    for(i = 0; i<tam;i++){
        free(m[i]);
    }
    free(m);

}


void main(){
    char **p;
    int tamLin = 5, tamCol = 7;

    //p = instancia_le_fgets(tamLin, tamCol);
    p = instancia_le_scanf(tamLin);

    exibe_matriz(p, tamLin);
    libera_matriz(p, tamLin);

}