#include <stdio.h>
#include <stdlib.h>

int *somaLinha(int tam, int **p){
    int *soma, i, j;

    soma = (int *) malloc(tam * sizeof(int));

    for(i = 0; i < tam; i++){
        soma[i] = 0;
        for(j = 0; j < tam; j++){
            soma[i] += p[i][j];
        }
    }



    return soma;
}

int main(){
    
    int tam,i,j, *soma, **p;
    printf("Digite o tamanho da matriz:\n");
    scanf("%d",&tam);

    p = (int **) malloc(tam * sizeof(int *));
    for(i = 0; i < tam; i++){
        p[i] = (int *) malloc(tam * sizeof(int));
    }

    printf("\nDigite os elementos da matriz:\n");
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            scanf("%d", &p[i][j]);	
        }		
    }
	
    printf("\n Exibindo a matriz: \n");
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            printf("%d ", p[i][j]);	
        }
        printf("\n");		
    }
	
    soma = somaLinha(tam, p);
    for(i=0;i<tam;i++){
        printf("Linha %d = %d\n",i,soma[i]);
    }

    //liberando a matriz
    for(i=0;i<tam;i++)
        free(p[i]);
    free(p);
    free(soma);
    
	
}