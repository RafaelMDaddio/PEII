#include <stdio.h>
#include <stdlib.h>

int main(){

    int tam,i,j, *soma;
    printf("Digite o tamanho da matriz:\n");
    scanf("%d",&tam);

    int p[tam][tam];
    
    printf("\nDigite os elementos da matriz:\n");
    for(i=0;i<3;i++){
	    for(j=0;j<3;j++){
		    scanf("%d", &p[i][j]);	
		}		
    }
	
    printf("\n Exibindo a matriz: \n");
    for(i=0;i<3;i++){
	    for(j=0;j<3;j++){
		    printf("%d ", p[i][j]);	
	    }
	    printf("\n");		
    }
	
    soma = somaLinha(tam,p); //implementar
    printf("\nExibindo a soma das linhas:\n");
    for(i=0;i<3;i++){
	    printf("Linha %d = %d\n",i,soma[i]);
    }
	
}