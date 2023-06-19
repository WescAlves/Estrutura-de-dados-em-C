#include <stdio.h>
#include <string.h>

struct funcionario {
	int matricula;
	char nome[100];
};

typedef struct funcionario Funcionario;

const int tam = 3;

void zerar(Funcionario *array){
	int k;
	for (k=0;k<tam;k++){
		array[k].matricula = -1;	
	}	
}

int esta_vazia(Funcionario *array){
	int k;
	for(k=0;k<tam;k++){
		if (array[k].matricula == -1||array[k].nome == "vazio"){
			return k;
		}
	}
	return tam;
}

void inserir (Funcionario *array){
	int posicao_disponivel = esta_vazia(array);
	if (posicao_disponivel != tam){
		printf("\nQual o nome do funcionario?\n");
		scanf("%s",&array[posicao_disponivel].nome);
		array[posicao_disponivel].matricula = posicao_disponivel;
	}
	else {
		printf("N foi possivel adicionar. Lista de funcionarios cheia.");
	}
}

void ver_funcionarios(Funcionario *array){
	int pos_preenchida = esta_vazia(array);
	if(pos_preenchida == 0){
		printf("\nA lista de funcionarios esta vazia\n");
	}
	else {
		int k;
		printf("\n---------------------------------------------------\n");
		for(k=0;k<pos_preenchida;k++){
			printf("\n Nome : %s \n", array[k].nome);
			printf("--------------------------------------------------\n");
		}
	}
}

void remover(Funcionario *array){
	int verificar = esta_vazia(array);
	if (verificar != 0) {
		char nome[100];
		int k;
		ver_funcionarios(array);
		printf("\nDigite o nome do funcionario que deseja remover.\n");
		scanf("%s",&nome);
		for(k=0;k<tam;k++){
			int comp = strcmp(array[k].nome,nome);
			if(comp == 0){
				if(array[k].matricula < tam - 1){
					int i;
					for(i=k;i<verificar;i++){
					strcpy(array[i].nome,array[i+1].nome);
					}
					strcpy(array[tam - 1].nome, "vazio");
				}
				else {
					strcpy(array[k].nome,"vazio");
				}
			}
		}
		printf("\nFuncionario removido.\n");
	}
	else {
		printf("\nA lista esta vazia. Por favor, adicione funcionarios na lista antes de tentar remover.\n");
	}	
}

