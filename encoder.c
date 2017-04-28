#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char letter;
	int freq;
}pair;

typedef struct {
	pair* data;
	treeNode* left;
	treeNode* right;
}treeNode;

typedef struct {
	treeNode* head;
}tree;

void usage(char *prog_name) {
	printf("Enter single line of text  < usage for %s >\n", prog_name);
	exit(0);
}

void fatal(char *message) {
	char error_message[100];

	strcpy(error_message, "[!!] Fatal Error ");
	strncat(error_message, message, 83);
	perror(error_message);
	exit(-1);
}

void *ec_malloc(unsigned int size) {
	void *ptr;
	ptr = malloc(size);
	if(ptr == NULL)
		fatal("in ec_malloc() on memory allocation");
	return ptr;
}

void swap(pair *list, int a, int b) {
	pair temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

void sortNodesRec(pair *list, int lo, int hi) {

	if(lo-hi >= 0)
		return;

	int pivot = hi;
	int wall = lo;

	for(int i = lo; i < hi; i++) {
		if(list[i].freq <= list[pivot].freq) {
			swap(list, wall, i);
			wall++;
		}

	}

	swap(list, wall, pivot);

	sortNodesRec(list, lo, wall-1);
	sortNodesRec(list, wall+1, hi);

}

void sortNodes(pair *list, int size) {
	sortNodesRec(list, 0, size-1);
}

void mergeNode(pair *list, int a, int b) {

}

int main(int argc, char *argv[]) {

	if(argc < 2)
		usage(argv[0]);

	int *freq_arr;

	freq_arr = (int *) ec_malloc(sizeof(int) * 30);

	for(int i = 0; i < 30; i++)
		freq_arr[i] = 0;

	char *buffer;

	buffer = (char *) ec_malloc(sizeof(char) * 80);

	strcpy(buffer, argv[1]);

	for(int i = 0; i < (int)strlen(buffer); i++) {
		if(buffer[i] == '.')
			freq_arr[26]++;
		else if(buffer[i] == ' ')
			freq_arr[27]++;
		else
			freq_arr[buffer[i]-97]++;
	}

	int char_count = 0;
	for(int i = 0; i < 30; i++) {
		if(freq_arr[i] > 0)
			char_count++;
	}

	pair *list;

	int list_length = char_count;

	list = (pair *) malloc(sizeof(pair) * list_length + 1);

	int j = 0;

	for(int i = 0; i < 26; i++) {
		if(freq_arr[i] > 0) {
			list[j].letter = i + 97;
			list[j].freq = freq_arr[i];
			j++;
		}
	}

	if(freq_arr[26] > 0) {
		list[j].letter = '.';
		list[j].freq = freq_arr[26];
		j++;
	}

	if(freq_arr[27] > 0) {
		list[j].letter = ' ';
		list[j].freq = freq_arr[27];
		j++;
	}

	sortNodes(list, list_length);

	for(int i = 0; i < list_length; i++) {
		printf("Node:\t%c occurs %d times\n\n", list[i].letter, list[i].freq);
	}

	tree huff;


	

	free(freq_arr);
	free(buffer);
	free(list);

	return 0;
}