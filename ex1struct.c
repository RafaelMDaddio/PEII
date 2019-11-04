#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TAM 10

typedef struct{
	int dia, mes, ano;
}Data;

typedef struct{
	char nome[20];
	float altura;
	Data d;
}Pessoa;

void criaData(Data *D){
	srand(time(NULL));
	
	D->dia = (rand() % 29) + 1;
	D->mes = (rand() % 11) + 1;
	D->ano = (rand() % 100) + 1919;
}

void lePessoa(Pessoa *p){
	printf("Digite o nome:\n");
	scanf("%s", p->nome);
	printf("Digite a altura:\n");
	scanf("%f", &p->altura);
	criaData(&p->d);
}

void exibePessoa(Pessoa p){
	printf("Nome: %s\n",p.nome);
	printf("Altura: %f\n",p.altura);
	printf("Data de nascimento: %d/%d/%d\n\n",p.d.dia,p.d.mes,p.d.ano);
}

int main(){
	
	Pessoa *p;
	int i;
	p = malloc(TAM * sizeof(Pessoa));
	for(i=0;i<TAM;i++){
		lePessoa(&p[i]);
	}
	
	for(i=0;i<TAM;i++){
		exibePessoa(p[i]);
	}
	
	free(p);
		
	return 0;
}
