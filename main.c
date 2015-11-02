#include <stdio.h>
#include <stdlib.h>
#include "bptree.h"

void print_menu(){
	printf("Digite um numero para adicionar; ou\n");
	printf("0 para imprimir árvore; ou\n");
	printf("-1 para sair; ou\n");
	printf("-2 para buscar; ou\n");
	printf("-3 para imprimir dados; ou\n");
	printf("-4 para alterar informação de um aluno; ou\n");
	printf("-9 para remover.\n");
}

int main( int argc, char* argv[] ) {
	unsigned _t = 0;
	FILE* f = NULL;

	if(argc > 1){
		f = fopen(argv[1],"r");
		if(f == NULL) printf("Arquivo não encontrado. Entrada via teclado.\n");
	}
	printf("Entre com o grau da árvore (>= 2): ");
	if (f != NULL) {
		fscanf(f, "%d", &_t);
		if( _t < 2 )
			f = NULL;
	}

	while(_t < 2)
		scanf(" %i", &_t);

	bp_tree * tree = init_tree(_t);

	int num = 0, from;
	char name[31];
	float cr;

	print_menu();
	
	while(num != -1) {
		if (f != NULL)
			fscanf(f, " %d", &num);
		else
			scanf(" %i", &num);

		if(num == -9){
			if (f != NULL)
				fscanf(f, " %d", &from);
			else 
				scanf(" %d", &from);

			tree = remove_key(tree, from);
			print_tree(tree, 0);
			printf("\n");
		} else if(num == -1){
			printf("\n");
			free_tree(tree);
			break;
		} else if(num == -2){
			printf("\n");
			if (f != NULL)
				fscanf(f, " %d", &from);
			else
				scanf(" %d", &from);

			printf("Nó (folha) com chave: %d\n", from);
			print_tree(search_key(tree, from), 0);
		} else if(num == -3){
			printf("\nDados armazenados: \n");
			print_data(tree);
		} else if(num == -4){
			if (f != NULL) {
				fscanf(f, " %d", &from);
				fscanf(f, " %30[^\n]", name);
				fscanf(f, " %f", &cr);
			} else {
				printf("Digite matrícula: ");
				scanf(" %d", &from);
				printf("Digite nome: ");
				scanf(" %30[^\n]", name);
				printf("Digite CR: ");
				scanf(" %f", &cr);
			}

			tree = edit_data(tree, from, make_ninfo(name, cr));
		} else if(!num){
			printf("\n");
			print_tree(tree, 0);
		} else {
			if (f != NULL) {
				fscanf(f, " %30[^\n]", name);
				fscanf(f, " %f", &cr);
			} else {
				printf("Digite nome: ");
				scanf(" %30[^\n]", name);
				printf("Digite CR: ");
				scanf(" %f", &cr);
			}	

			printf("Inserindo chave: %d\n", num);
			tree = insert_key(tree, num, make_ninfo(name, cr));
		}
		if(f != NULL && feof(f)){
			fclose(f);
			f = NULL;
			print_menu();
		}
	}

	return 0;
}