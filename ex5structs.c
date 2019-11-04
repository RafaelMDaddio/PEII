#include<stdio.h>
#include<stdlib.h>

#define TAM 3

typedef struct{
	char nome[20];
	int ano;
	float duracao;
}Filme;

typedef struct{
	char nome[20];
	int qtdFilmes;
	Filme *filmes;
}Diretor;

void leFilmes(Filme *f, int tam){
	int i = 0;
	for(i=0;i<tam;i++){
		printf("Digite o nome do filme %d\n",i+1);
		scanf("%s",f[i].nome);
		printf("Digite o ano do filme %d\n",i+1);
		scanf("%d", &f[i].ano);
		printf("Digite a duracao do filme %d\n",i+1);
		scanf("%f", &f[i].duracao);
	}
}
void leDiretor(Diretor *d){
	printf("Digite o nome do diretor: \n");
	scanf("%s",d->nome);
	printf("Quantos filmes ele fez?\n");
	scanf("%d", &d->qtdFilmes);
	d->filmes = malloc(d->qtdFilmes * sizeof(Filme));
	leFilmes(d->filmes,d->qtdFilmes);
}

void exibeDiretor(Diretor d){
	int i;
	printf("Nome: %s\n", d.nome);
	printf("Filmes:\n");
	for(i=0;i<d.qtdFilmes;i++){
		printf("- %s: ano %d, duracao %f\n", d.filmes[i].nome, d.filmes[i].ano, d.filmes[i].duracao);
	}
	
}

void buscaDiretor(Diretor *d, int tam, char *nome){
	int i;
	for(i=0;i<tam;i++){
		if(strcmp(d[i].nome,nome) == 0){
			exibeDiretor(d[i]);
		}
	}
	
}

int main(){
	
	Diretor *d;
	int i;
	char nomeDiretor[20];
	d = malloc(TAM * sizeof(Diretor));
	
	for(i=0;i<TAM;i++){
		leDiretor(&d[i]);
	}
	
	do{
		printf("Qual diretor está pesquisando?");
		scanf("%s",nomeDiretor);
		if(strcmp(nomeDiretor,"OOO") == 0){
			break;
		}
		buscaDiretor(d, TAM, nomeDiretor);
		
		
	}while(1);
	
	return 0;
}
