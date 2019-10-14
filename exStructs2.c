#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char rua[20];
    int numero;
}Endereco;

typedef struct{
    char nome[20];
    char telefone[12];
    Endereco end;
}Pessoa;

typedef struct{
    Pessoa *listaPessoas;
}Agenda;

void leContato(Agenda *a, int pos){
    
    printf("Digite o nome do contato numero %d\n", pos);
    scanf("%s", a->listaPessoas[pos].nome);
    fflush(stdin);
    
    printf("Digite o telefone do contato numero %d\n", pos);
    scanf("%s", a->listaPessoas[pos].telefone);
    fflush(stdin);
    
    printf("Digite a rua do contato numero %d \n",pos);
    scanf("%s", a->listaPessoas[pos].end.rua);
    fflush(stdin);
    
    printf("Digite o numero da casa do contato numero %d\n",pos);
    scanf("%d", &a->listaPessoas[pos].end.numero);
    fflush(stdin);   
}

void exibeContato(Pessoa p){
    printf("\n\nNome: %s\n",p.nome);
    printf("Telefone: %s\n",p.telefone);
    printf("Endereco: %s, %d.\n",p.end.rua,p.end.numero);
}

int main(){
    Agenda a;
    int x;
    printf("Quantos contatos voce quer?\n");
    scanf("%d",&x);
    fflush(stdin);

    a.listaPessoas = malloc(x * sizeof(Pessoa));
    for(int i = 0; i < x; i++){
        leContato(&a, i);
        exibeContato(a.listaPessoas[i]);
    }
    free(a.listaPessoas);

}