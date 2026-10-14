#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bibca.h"

#define TAM 10000000

void main(){
	system("clear");

	srand(time(NULL));

	int *vet = (int *)malloc(TAM * sizeof(int));

	geravet(vet,TAM);
	//imprimevet(vet, TAM);
	tempg(vet, TAM);

	srcvet(vet, TAM);

	printf("\n\nPressione ENTER para sair..");
	getchar();
	getchar();

	free(vet);
}

void geravet(int vet[], int tam){
	int i;

	for(i = 0;i < tam;i++){
		vet[i] = rand();
	}
}

void imprimevet(int vet[], int tam){
	int i;

	printf("\n");
	for(i = 0;i < tam;i++){
		printf(" %d", vet[i]);
	}
}

void srcvet(int vet[], int tam){
	int pos;

	printf("\nBuscar (0 a %d)\nDigite: ", tam - 1);
	scanf("%d",&pos);

	if(pos >= 0 && pos < tam){
		printf("\nO Valor Armazenado na Posição [%d] é %d\n", pos, vet[pos]+1);
	}else{
		printf("\nERRO!");
		getchar();
	}
}

void tempg(int vet[], int tam){
	clock_t i, f;
	double temp;

	i = clock();

	geravet(vet, tam);

	f = clock();

	temp = ((double)(f - i))/CLOCKS_PER_SEC;
	printf("\nTempo de Geração: \n%f segundos\n",tam, temp);
}
