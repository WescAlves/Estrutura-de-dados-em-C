//funcoes dedicadas a operacoes com lista

typedef struct no{
	struct no* anterior;
	char nome[30];  //neste campo, implemente a estrutura de dados desejada. neste caso, funcionario.
	struct no* prox;	
}No;

typedef struct lista{
	No* inicio;
}Lista; 

Lista* criar_Lista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if (lista != NULL){
	lista -> inicio = NULL;
	return lista;
	}
	else {
		return NULL;
	}
}

void ver_funcionarios (No* no) {
	printf("\n-------------------------------------\n");
	printf("\nNome: %s\n", no -> nome);
	printf("\n------------------------------\n");
}

void percorrer_lista (Lista* lista){ //este subprograma percorre a lista inteira e faz chamada para o subprograma desejado a cada laço
	if(lista -> inicio == NULL){
		printf("\n A lista esta vazia!\n");
		
	}
	else {
		No* aux = lista -> inicio;
		while(aux -> prox != NULL){
			ver_funcionarios(aux);
			aux = aux -> prox;
		}	
	}
}

void adicionar_no_inicio (No* novo, Lista* lista){
	if (novo != NULL) {
		novo -> prox = lista -> inicio;
		if (lista -> inicio != NULL){
			novo -> anterior = lista -> inicio -> anterior;
		}
		else{
			novo -> anterior = NULL;
		}
		lista -> inicio = novo;
	}
	else {
		printf("n foi possivel adicionar");
	}
}

int remover_da_lista(No* no){
	No* aux = no;
	if(aux -> anterior != NULL) {
		aux -> anterior -> prox = aux -> prox;
	}
	if(aux -> prox != NULL){
		aux -> prox -> anterior = aux -> anterior;
	}
	free(aux);
	return 1;
}

void deletarLista(Lista* lista) {
    No* pivo = lista -> inicio;
    No* temp;
    while (pivo != NULL) {
        temp = pivo;
        pivo = pivo -> prox;
        free(temp);
    }
    free(lista);
	lista -> inicio = NULL; 
}




//funcoes dedicadas a operacoes com funcionarios





No* localizar(No* no, char nome[50]){
	if(no == NULL){
		return NULL;
	}
	int comp = strcmp(no -> nome, nome);
	if (comp == 0 ){
		return no;
	}
	return localizar(no -> prox, nome);
}


void adicionar(Lista* lista){
    No* novo =(No*) malloc(sizeof(No));
	printf("\n-------------------------------\n");
	printf("\nQual o nome do funcionario?\n");
	scanf("%s", &novo -> nome);
	adicionar_no_inicio(novo, lista);
}

void remover(Lista* lista){
	if (lista -> inicio == NULL){
		printf("a lista esta vazia");
	}
	else {
		char nome[50];
		printf("\n Qual funcionario deseja remover?");
		scanf("%s", &nome);
    	No* funcionario = localizar(lista -> inicio , nome);
		int removido = remover_da_lista(funcionario);
		if(removido == 1){
			printf("\nFuncionario removido!\n");
		} 
		else {
			printf("\nFuncionario n existe ou n existe nenhum!\n");
		}
	}
}

