#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibettr.h"
#define max 100

void menu(){

	struct Ponto ponto[max];
	int total = 0;
	int op;
	rcpdados(ponto, &total);

	do{
		system("clear");
		printf("\n");
		printf("╔════════════════════════════════════════╗\n");
    		printf("║       CONTROLE DE PONTO	         ║\n");
    		printf("╠════════════════════════════════════════╣\n");
    		printf("║ 1. Registrar (Entrada/Saída)           ║\n");
    		printf("║ 2. Listar Histórico            	 ║\n");
    		printf("║ 3. Limpar Histórico                    ║\n");
		printf("║ 4. Salvar e Sair                       ║\n");
		printf("╚════════════════════════════════════════╝\n");
		printf("Escolha a Opção Desejada: ");
		scanf("%d",&op);
		getchar();

		switch(op){
			case 1:
				rgtponto(ponto, &total);
				break;
			case 2:
				lsponto(ponto, total);
				break;
			case 3:
				limpah(ponto, &total);
				break;
			case 4:
				salvadados(ponto, total);
				printf("\nEncerrando...\n");
				printf("\nPressione ENTER para Finalizar ");
				getchar();
				system("clear");
				break;
		}
	}while(op != 4);
}

//rgtponto = registro de ponto
void rgtponto(struct Ponto ponto[], int *total){
	system("clear");

	if(*total < max){
		printf("\nRegistrar Novo Ponto\n");

		printf("Data (--/--/----): ");
		scanf("%s", ponto[*total].data);

		printf("Horário: (--:--): ");
		scanf("%s", ponto[*total].hora);

		printf("Tipo (Entrada/Saída): ");
		scanf("%s", ponto[*total].tipo);

		(*total)++;
		salvadados(ponto, *total);
		printf("\nPonto Registrado com Sucesso!\n");
	}else{
		printf("\nLimite Máximo de Registro Atingidos!\n");
	}
}

//lsponto = listar ponto.
void lsponto(struct Ponto ponto[], int total){
	system("clear");

	int i;

	if(total == 0){
		printf("\nNenhum Ponto Registrado no Histórico\n");
	}else{
		printf("\nHistórico de Pontos\n");
		printf("N° | Data | Hora | Tipo\n");

		for(i = 0; i < total;i++){
			printf("%-3d | %-10s | %-5s | %-s\n",
				i + 1,
				ponto[i].data,
				ponto[i].hora,
				ponto[i].tipo);
		}
	}
	printf("\nPressione ENTER para Voltar...");
	getchar();
}

//rcpdados = recuperar dados.
void rcpdados(struct Ponto ponto[], int *total){
	FILE *fp = fopen("ponto.bin","rb");
	if(fp == NULL){
		*total = 0;
		return;
	}
	*total = fread(ponto, sizeof(struct Ponto), max, fp);
	fclose(fp);
}

void salvadados(struct Ponto ponto[], int total){
	FILE *fp = fopen("ponto.bin", "wb");
	if(fp == NULL){
		printf("[Erro ao Salvar]\n");
		return;
	}
	fwrite(ponto, sizeof(struct Ponto), total, fp);
	fclose(fp);
}

void limpah(struct Ponto ponto[], int *total){
	*total = 0;

	remove("ponto.bin");
	printf("\nHistórico Limpo com Sucesso!\n");
	printf("\nPressione ENTER para Voltar...");
	getchar();
}
