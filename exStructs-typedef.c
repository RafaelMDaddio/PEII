#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCPF 11 //constante, TAMCPF vale 11

typedef struct{
    char nome[20];
    int cpf[TAMCPF];
    float salario;
}Pessoa; 

Pessoa x;


//funcao inserePessoa retorna uma copia de Pessoa p
Pessoa inserePessoa(){
    Pessoa p;
    printf("Digite seu nome\n");
    scanf("%s",p.nome);
    printf("Digite seu CPF (somente numeros, aperte ENTER a cada numero)\n");
    for(int i = 0; i < TAMCPF; i++){
        scanf("%d", &p.cpf[i]);
    }
    printf("Digite seu salario\n");
    scanf("%f", &p.salario);
    return p;

}

//funcao exibePessoa recebe um Pessoa por valor (uma copia)
void exibePessoa(Pessoa p){
    printf("\nNome: %s \n", p.nome);
    printf("CPF: ");
    for(int i=0;i<TAMCPF;i++){
        if((i == 3) || (i == 6)){
            printf(".");
        }
        if(i == 9){
            printf("-");
        }
        printf("%d", p.cpf[i]);
    }
    printf("\nSalário: %.2f \n", p.salario);
}

int main(){

    //lidando com a variavel global Pessoa x
    strcpy(x.nome,"Joao");

    for(int i=0; i< TAMCPF;i++){
        x.cpf[i] = 0;
    }
    x.salario = 700.50;
    exibePessoa(x);

    //criando uma variavel local Pessoa p
    Pessoa p;
    strcpy(p.nome,"Joana");
    for(int i=0; i< TAMCPF;i++){
        p.cpf[i] = 1;
    }
    p.salario = 700.50;
    exibePessoa(p);

    //criando um vetor de Pessoa
    Pessoa pessoas[2];
    for(int i = 0; i < 2;i++){
        pessoas[i] = inserePessoa();
    }
    for(int i = 0; i < 2; i++){
        exibePessoa(pessoas[i]);
    }

}