#include <stdio.h>
#include "bptree.h"

int main(){
	bp_tree * tree = init_tree();
	int num = 0, from;
	char name[31];
	float cr;
	printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
	while(num != -1){
		scanf(" %i", &num);
		if(num == -9){
		  scanf("%d", &from);
		  tree = remove_key(tree, from);
		}
		else if(num == -1){
		  printf("\n");
		  // print_tree(tree, 0);
		  free_tree(tree);
		  break;
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