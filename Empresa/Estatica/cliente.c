#include <stdio.h>
#include <string.h>

#include "funcionario_estatico.h"

typedef struct funcionario Funcionario;

void menu(Funcionario *array){
	int opcao;
	printf ("\n                  ---------- Controle de RH ----------- \n");
	printf("                                --- gdLOG ---");
	printf("\n                               Menu de opcoes:\n\n");
	printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n\n");
	printf ("			| 1-Inserir funcionario |\n");
	printf ("			| 2-Remover Funcionario |\n");
	printf ("			| 3- Ver Funcionarios   |\n");
	printf ("			| 4- Deletar lista   |\n");
	scanf ("%d",&opcao);
	controlador(array, opcao);
}

int controlador(Funcionario *array, int opcao){
	
	switch (opcao) {
			case 0 :
				break;
			case 1 :
				inserir(array);
				break;
			case 2 :
				remover(array);
				break;
			case 3:
				ver_funcionarios(array);
				break;
			case 4:
				//apagar();
				break;
			default:
				printf ("Opcao invalida. Digite uma opcao valida!");
				break;
}

return opcao;
}

int main (void){
	Funcionario array[tam];
	zerar(array);
	do{
		menu(array);
	}while(1);
	
	return 0;
}
