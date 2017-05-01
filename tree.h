/**
Helper functions for encoding the data using huffman encoding.

Also includes tree, treeNode, and pair structs
**/

#ifndef TREE_H
#define TREE_H

/**
Struct for storing final encoding and character
**/
typedef struct _pair pair;
struct _pair {
	char c;
	char huff_code[10];
};

/**
treeNodes make up the huffman tree. Store character, freqency of that character, and left/right treeNodes
**/
typedef struct _treeNode treeNode;
struct _treeNode {
	char letter;
	int freq;
	treeNode* left;
	treeNode* right;
};

/**
tree struct. Only stores head of tree
**/
typedef struct _tree tree;
struct _tree {
	treeNode* head;
};

/**

**/
void usage(char* prog_name);

void fatal(char* message);

void* ec_malloc(unsigned int size);

void swap(treeNode* node_list[], int a, int b);

void sortNodes(treeNode* node_list[], int lo, int hi);

int mergeNode(treeNode* node_list[], int start_list);

void freeTree(treeNode* head);

void printNode(treeNode* head);

void printTree(treeNode* head);

void findLetter(treeNode* head, char c[], pair* code_list);

void encode(char* ret_buffer, char* buffer, pair* code_list, int list_length);

#endif