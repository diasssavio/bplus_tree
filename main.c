#include <stdio.h>
#include "bptree.h"

int main(){
	bp_tree * tree = init_tree();
	int num = 0, from;
	char name[31];
	float cr;
	printf("Digite um numero para adicionar; ou\n");
	printf("0 para imprimir árvore; ou\n");
	printf("-2 para buscar; ou\n");
	printf("-3 para imprimir dados; ou\n");
	printf("-4 para alterar informação de um aluno; ou\n");
	printf("-9 para remover; ou\n");
	printf("-1 para sair\n");
	while(num != -1){
		scanf(" %i", &num);
		if(num == -9){
		  scanf(" %d", &from);
		  tree = remove_key(tree, from);
		}
		else if(num == -1){
		  printf("\n");
		  // print_tree(tree, 0);
		  free_tree(tree);
		  break;
		}
		else if(num == -2){
		  printf("\n");
		  scanf(" %d", &from);
		  printf("Nó (folhx) com chave: %d\n", from);
		  print_tree(search_key(tree, from), 0);
		}
		else if(num == -3){
		  printf("\nDados armazenados: \n");
		  print_data(tree);
		}
		else if(num == -4){
		  printf("Digite matrícula: \n");
		  scanf(" %d", &from);
		  printf("Digite nome: \n");
		  scanf(" %30[^\n]", name);
		  printf("Digite CR: \n");
		  scanf(" %f", &cr);
		  tree = edit_data(tree, from, make_ninfo(name, cr));
		}
		else if(!num){
		  printf("\n");
		  print_tree(tree, 0);
		}
		else { 
			scanf(" %30[^\n]", name);
			scanf(" %f", &cr);
			printf("Inserindo chave: %d\n", num);
			tree = insert_key(tree, num, make_ninfo(name, cr));
			print_tree(tree, 0);
		}
	}
	return 0;
}