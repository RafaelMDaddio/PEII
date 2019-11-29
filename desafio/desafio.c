#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cont{
    char nome[100];
    char endereco[200];
    int idade;

}contato;

void leArquivo(FILE *arq){
    contato c;

    int nR=0;

    if(nR = fread(&c,sizeof(contato),1,arq) == 0){
        printf("Não há registros ainda!\n\n");
    }
    rewind(arq);
    while(nR= fread(&c,sizeof(contato),1,arq) == 1){
        
        printf("Nome %s\n",c.nome);
        printf("Endereco: %s\n",c.endereco);
        printf("Idade: %d\n\n", c.idade);
    }
}

int insereRegistro(FILE *arq){
    contato c,cAux;
    int achei=0, nR=0,nW=0;

    //lendo o contato fornecido pelo usuario
    printf("Digite o nome: ");
    scanf("%s",c.nome);
    printf("Digite o endereco: ");
    scanf("%s",c.endereco);
    printf("Digite a idade: ");
    scanf("%d",&c.idade);

    //se arquivo vazio
    if(nR = fread(&cAux,sizeof(contato),1,arq) == 0){
        nW = fwrite(&c,sizeof(contato),1,arq);
        return 1;
        
    }
    rewind(arq);
    
    //procurando a posicao certa
    do{
        nR = fread(&cAux,sizeof(contato),1,arq);
        if(nR == 1){
            if(strcmp(cAux.nome,c.nome) > 0){
                achei = 1;
            }
        }        
    }while(achei == 0 && nR == 1);

    //se o que estou guardando eh o ultimo nome
    if(achei == 0){
        nW = fwrite(&c,sizeof(contato),1,arq);
    }
    else{ //senao, devo fazer o shift
        do{
            fseek(arq,-sizeof(contato),SEEK_CUR);
            nW = fwrite(&c,sizeof(contato),1,arq);
            c = cAux;
            nR = fread(&cAux,sizeof(contato),1,arq);
        }while(nR == 1);
        
        fwrite(&c,sizeof(contato),1,arq);

    }

    return 1;
}

int main(int argc, char *argv[]){
    
    if(argc == 2){
        FILE *arq;
        int op;

        arq = fopen(argv[1],"r+b");
        if(arq == NULL){
            arq = fopen(argv[1],"w+b");
            if(arq == NULL){
                printf("Erro ao abrir o arquivo");
                return 0;
            }
        }

        while(1){
            printf("\nQual a opcao?\n1-Cadastrar novo contato\n2-Exibir contatos\n3-Sair\n");
            scanf("%d", &op);
            switch(op){
                case 1: insereRegistro(arq);
                        rewind(arq);
                        break;
                case 2: leArquivo(arq);
                        rewind(arq);
                        break;
                case 3: fclose(arq);
                        return 0;
                default: printf("Opcao invalida \n\n");
            }
        }
    
    }

}
