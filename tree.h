#ifndef TREE_H
#define TREE_H

typedef struct _pair pair;
struct _pair {
	char c;
	char huff_code[10];
};

typedef struct _treeNode treeNode;
struct _treeNode {
	char letter;
	int freq;
	char huff_code[10];
	treeNode* left;
	treeNode* right;
};

typedef struct _tree tree;
struct _tree {
	treeNode* head;
};

void usage(char* prog_name);

void fatal(char* message);

void* ec_malloc(unsigned int size);

void swap(treeNode* node_list[], int a, int b);

void sortNodes(treeNode* node_list[], int lo, int hi);

int mergeNode(treeNode* node_list[], int start_list);

void free_tree(treeNode* head);

void printNode(treeNode* head);

void print_tree(treeNode* head);

void find_letter(treeNode* head, char c[], pair* code_list);

void encode(char* ret_buffer, char* buffer, pair* code_list, int list_length);

#endif