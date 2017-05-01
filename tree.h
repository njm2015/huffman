#ifndef TREE_H
#define TREE_H

struct _pair {
	char c;
	char huff_code[10];
};

struct _treeNode {
	char letter;
	int freq;
	char huff_code[10];
	struct treeNode* left;
	struct treeNode* right;
};

struct _tree {
	treeNode* head;
};

void swap(treeNode* node_list[], int a, int b);

void sortNodes(treeNode* node_list[], int lo, int hi);

int mergeNode(treeNode* node_list[], int start_list);

void free_tree(treeNode* head);

void printNode(treeNode* head);

void print_tree(treeNode* head);

void find_letter(treeNode* head, char c[], pair* code_list);

void encode(char* ret_buffer, char* buffer, pair* code_list, int list_length);

#endif