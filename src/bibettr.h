struct Ponto{
	char data[15];
	char hora[10];
	char tipo[20];
};

void menu();
void rgtponto(struct Ponto ponto[], int *total);
void lsponto(struct Ponto ponto[], int total);
void rcpdados(struct Ponto ponto[], int *total);
void salvadados(struct Ponto ponto[], int total);
void limpah(struct Ponto ponto[], int *total);
