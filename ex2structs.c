#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float *x,*y,*z;
}Ponto;

void aloca(Ponto *p){
	p->x = malloc(sizeof(float));
	p->y = malloc(sizeof(float));
	p->z = malloc(sizeof(float));	
}

void libera(Ponto *p){
	free(p->x);
	free(p->y);
	free(p->z);
}

void lePonto(Ponto *p){
	printf("Coordenada x:\n");
	scanf("%f", p->x);
	printf("Coordenada y:\n");
	scanf("%f", p->y);
	printf("Coordenada z:\n");
	scanf("%f", p->z);
}

float calculaDistancia(Ponto a, Ponto b){
	return sqrt(pow(*(a.x) - *(b.x),2) + pow(*(a.y) - *(b.y),2) + pow(*(a.z) - *(b.z),2));
}

int main(){
	
	Ponto a, b;
	aloca(&a);
	aloca(&b);
	
	lePonto(&a);
	lePonto(&b);
	
	float res = calculaDistancia(a,b);
	printf("A distancia eh de: %f", res);
	
	libera(&a);
	libera(&b);
	
	return 0;
}
