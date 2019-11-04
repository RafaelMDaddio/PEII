#include<stdio.h>
#include<stdlib.h>

#define TAM 5

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
	
	Aluno *a, *acimaMedia, *abaixoMedia;
	int i, nAcima=0, nAbaixo=0;
	a = malloc(TAM*sizeof(Aluno));
	
	for(i=0;i<TAM;i++){
		leAluno(&a[i]);
		calculaMedia(&a[i]);
	}
	ordena(a,TAM);
	
	for(i=0;i<TAM;i++){
		if(a[i].media >= 6){
			nAcima++;
		}
		else{
			nAbaixo++;
		}
	}
	
	if(nAcima > 0){
		acimaMedia = malloc(nAcima * sizeof(Aluno));
		for(i=0;i<nAcima;i++){
			acimaMedia[i]=a[i];
		}
		printf("\nAlunos acima da media:\n");
		for(i=0;i<nAcima;i++){
			exibeAluno(&acimaMedia[i]);
		}
		free(acimaMedia);
	}
	
	if(nAbaixo > 0){
		abaixoMedia = malloc(nAbaixo * sizeof(Aluno));
		for(i=0;i<nAbaixo;i++){
			abaixoMedia[i]=a[i+nAcima];
		}
		printf("\nAlunos abaixo da media:\n");
		for(i=0;i<nAbaixo;i++){
			exibeAluno(&abaixoMedia[i]);
		}
		free(abaixoMedia);
	}
	
	free(a);
	return 0;
}
