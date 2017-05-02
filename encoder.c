#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define ARR_SIZE	30
#define FILE_SIZE 	500

int main(int argc, char *argv[]) {

	if(argc < 2)
		usage(argv[0]);

	int* freq_arr = (int*) ec_malloc(sizeof(int) * ARR_SIZE);

	initFreqArr(freq_arr, ARR_SIZE);

	char* buffer = (char*) ec_malloc(sizeof(char) * 80);

	strcpy(buffer, argv[1]);

	indexFreq(buffer, freq_arr);

	int list_length = getListLength(freq_arr, ARR_SIZE);

	treeNode* node_list[list_length];

	int j = 0;

	for(int i = 0; i < 26; i++) {
		if(freq_arr[i] > 0) {
			node_list[j] = (treeNode*) ec_malloc(sizeof(treeNode));
			node_list[j]->letter = i + 97;
			node_list[j]->freq = freq_arr[i];
			node_list[j]->left = NULL;
			node_list[j]->right = NULL;
			j++;
		}
	}

	if(freq_arr[26] > 0) {
		node_list[j] = (treeNode*) ec_malloc(sizeof(treeNode));
		node_list[j]->letter = '.';
		node_list[j]->freq = freq_arr[26];
		node_list[j]->left = NULL;
		node_list[j]->right = NULL; 
		j++;
	}

	if(freq_arr[27] > 0) {
		node_list[j] = (treeNode*) ec_malloc(sizeof(treeNode));
		node_list[j]->letter = ' ';
		node_list[j]->freq = freq_arr[27];
		node_list[j]->left = NULL;
		node_list[j]->right = NULL;
		j++;
	}

	sortNodes(node_list, 0, list_length-1);

	for(int start_list = 0; start_list < list_length - 1;) {
		start_list = mergeNode(node_list, start_list);
		sortNodes(node_list, start_list, list_length-1);
	}

	tree* huff = (tree*) ec_malloc(sizeof(tree));
	huff->head = node_list[list_length-1];

	pair* code_list = (pair*) ec_malloc(sizeof(pair) * list_length);

	for(int i = 0; i < list_length; i++) {
		code_list[i].c = '\0';
	}

	findLetter(huff->head, "", code_list);

	char* ret_buffer = (char*) ec_malloc(sizeof(char) * 80);

	encode(ret_buffer, buffer, code_list, list_length);

	printf("Enocded string: %s\n", ret_buffer);

	free(freq_arr);
	free(buffer);	
	free(code_list);
	free(ret_buffer);
	freeTree(huff->head);
	free(huff->head);
	free(huff);

	return 0;
}