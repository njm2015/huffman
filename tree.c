#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void usage(char* prog_name) {
	printf("Enter single line of text  < usage for %s >\n", prog_name);
	exit(0);
}

void fatal(char* message) {
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}

void* ec_malloc(unsigned int size) {
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL)
		fatal("in ec_malloc() on memory allocation");
	return ptr;
}

void initFreqArr(int* freq_arr, int size) {
	for(int i = 0; i < size; i++)
		freq_arr[i] = 0;
}

void indexFreq(char* buffer, int* freq_arr) {
	for(int i = 0; i < (int)strlen(buffer); i++) {
		if(buffer[i] == '.')
			freq_arr[26]++;
		else if(buffer[i] == ' ')
			freq_arr[27]++;
		else
			freq_arr[buffer[i]-97]++;
	}
}

int getListLength(int* freq_arr, int size) {
	int list_length = 0;

	for(int i = 0; i < 30; i++) {
		if(freq_arr[i] > 0)
			list_length++;
	}

	return list_length;
}

void swap(treeNode* node_list[], int a, int b) {
	treeNode* temp = node_list[a];
	node_list[a] = node_list[b];
	node_list[b] = temp;
}

void sortNodes(treeNode* node_list[], int lo, int hi) {

	if(lo-hi >= 0)
		return;

	int pivot = hi;
	int wall = lo;

	for(int i = lo; i < hi; i++) {
		if(node_list[i]->freq <= node_list[pivot]->freq) {
			swap(node_list, wall, i);
			wall++;
		}
	}

	swap(node_list, wall, pivot);

	sortNodes(node_list, lo, wall-1);
	sortNodes(node_list, wall+1, hi);

}

int mergeNode(treeNode* node_list[], int start_list) {
	
	treeNode* parent = (treeNode*) ec_malloc(sizeof(treeNode));

	parent->left = node_list[start_list];
	parent->right = node_list[start_list+1];

	parent->letter = '\0';
	parent->freq = node_list[start_list]->freq + node_list[start_list+1]->freq;

	node_list[start_list+1] = parent;

	return start_list + 1;
}

void freeTree(treeNode* head) {

	if(head->left == NULL) {
		return;
	}

	freeTree(head->left);
	freeTree(head->right);

	free(head->left);
	free(head->right);
}

void printNode(treeNode* head) {
	if(head == NULL)
		printf("NULL");
	printf("Node %c with freq %d\n\n", head->letter, head->freq);
}

void printTree(treeNode* head) {	
	if(!head->left) {
		printNode(head);
		return;
	}

	printTree(head->left);
	printTree(head->right);
}


void findLetter(treeNode* head, char c[], pair* code_list) {
	if(!(head->left)) {
		int i = 0;
		while(code_list[i].c != '\0')
			i++;
		code_list[i].c = head->letter;
		strcpy(code_list[i].huff_code, c);
		return;
	}

	char left[10];
	char right[10];

	strcpy(left, c);
	strcpy(right, c);

	strcat(left, "0");
	strcat(right, "1");

	findLetter(head->left, left, code_list);
	findLetter(head->right, right, code_list);
}

void encode(char* ret_buffer, char* buffer, pair* code_list, int list_length) {
	for(int i = 0; i < strlen(buffer); i++) {

		char curr_code[10] = "";

		for(int k = 0; k < list_length; k++) {
			if(code_list[k].c == buffer[i])
				strcpy(curr_code, code_list[k].huff_code);
		}

		strcat(ret_buffer, curr_code);
	}
}