#include<stdio.h>
#include<stdlib.h>

#define TAM 10

typedef struct{
	char nome[20];
	int codDisciplina;
	float n1,n2,media;
}Aluno;

void leAluno(Aluno *a){
	printf("Digite o nome:\n");
	scanf("%s", a->nome);
	printf("Digite o codigo da disciplina:\n");
	scanf("%d", &a->codDisciplina);
	printf("Digite suas 2 notas:\n");
	scanf("%f %f",&a->n1, &a->n2);
}

void exibeAluno(Aluno *a){
	printf("\nNome: %s\n",a->nome);
	printf("Codigo disciplina: %d\n", a->codDisciplina);
	printf("Media: %f\n",a->media);
}

void calculaMedia(Aluno *a){
	a->media = (a->n1 + a->n2)/2;
}

void ordena(Aluno *a, int tam){
	int i,j,tam2=tam;
	Aluno aux;
	
	for(i=0;i<tam;i++){
		for(j=0;j<tam2-1;j++){
			if(a[j].media < a[j+1].media){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
		tam2--;
	}
	
}

int main(){
	
	Aluno *a;
	int i;
	a = malloc(5*sizeof(Aluno));
	
	for(i=0;i<TAM;i++){
		leAluno(&a[i]);
		calculaMedia(&a[i]);
	}
	
	ordena(a,TAM);
	
	for(i=0;i<TAM;i++){
		exibeAluno(&a[i]);
	}
	
	free(a);
	
	return 0;
}
