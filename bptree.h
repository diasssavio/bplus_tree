#ifndef B_TREE_H_
#define B_TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// B+ tree degree
// #define t 2

static unsigned t = 2;

typedef struct nodeinfo{
	char name [31];
	float grade;
} info;

/**
 * B+ tree structure
 * keys_number: number of keys on each node
 * is_leaf: "binary" variable that indicates whether a node is leaf or not
 * keys: a vector containing the keys on the node
 * data: vector for the main info of the current key 
 * children: a vector of pointers to the inner nodes' children.
 * next: used to make the linked list in the leaves
 */
typedef struct bptree{
	unsigned keys_number;
	unsigned is_leaf;
	int * keys;
	info ** data;
	struct bptree ** children;
	struct bptree * next;
} bp_tree;

bp_tree* init_tree( unsigned );
bp_tree* make_node();
void free_node( bp_tree* );
info * make_ninfo( char*, float );
void free_ninfo( info* );
void print_tree( bp_tree*, unsigned );
void print_data( bp_tree* );
bp_tree* divide_node( bp_tree*, int, bp_tree* );
bp_tree* partial_insert( bp_tree*, int, info* );
bp_tree* insert_key( bp_tree*, int, info* );
bp_tree* free_tree( bp_tree* );
bp_tree* search_key( bp_tree*, int );
bp_tree* edit_data( bp_tree*, int, info* );
bp_tree* remove_key( bp_tree*, int );
bp_tree* _remove_key( bp_tree*, int );

#endif /* B_TREE_H_ */