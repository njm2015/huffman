#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair {
	char letter;
	int freq;
}pair;

typedef struct treeNode {
	pair* data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

typedef struct tree {
	treeNode* head;
}tree;

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

void swap(treeNode* node_list, int a, int b) {
	treeNode temp = node_list[a];
	node_list[a] = node_list[b];
	node_list[b] = temp;
}

void sortNodes(treeNode* node_list, int lo, int hi) {

	if(lo-hi >= 0)
		return;

	int pivot = hi;
	int wall = lo;

	for(int i = lo; i < hi; i++) {
		if(node_list[i].data->freq <= node_list[pivot].data->freq) {
			swap(node_list, wall, i);
			wall++;
		}
	}

	swap(node_list, wall, pivot);

	sortNodes(node_list, lo, wall-1);
	sortNodes(node_list, wall+1, hi);

}

int mergeNode(treeNode* node_list, int start_list) {
	
	treeNode* parent = (treeNode*) ec_malloc(sizeof(treeNode));

	pair* temp = (pair*) ec_malloc(sizeof(pair));

	*parent->left = node_list[start_list];
	*parent->right = node_list[start_list+1];

	temp->freq = node_list[start_list].data->freq + node_list[start_list+1].data->freq;
	temp->letter = '\0';
	parent->data = temp;

	node_list[start_list+1] = *parent;

	return start_list + 1;
}

void free_tree(treeNode* head) {

	if(head->left == NULL) {
		printf("here\n");
		return;
	}

	free_tree(head->left);
	free_tree(head->right);

	free(head->left);
	free(head->right);
}

void print_tree(treeNode* head) {	
	if(!head->left) {
		printf("Node %c with freq %d\n", head->data->letter, head->data->freq);
		return;
	}

	print_tree(head->left);
	print_tree(head->right);
}

void printNode(treeNode* head) {
	if(head == NULL)
		printf("NULL");
	printf("Node %c with freq %d\n", head->data->letter, head->data->freq);
}

/*
char find_letter(treeNode* head, char c) {
	if(!(head->left))
		return '\0'; 
}
*/
int main(int argc, char *argv[]) {

	if(argc < 2)
		usage(argv[0]);

	int* freq_arr;

	freq_arr = (int *) ec_malloc(sizeof(int) * 30);

	for(int i = 0; i < 30; i++)
		freq_arr[i] = 0;

	char* buffer;

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

	pair* list;

	int list_length = char_count;

	list = (pair*) ec_malloc(sizeof(pair) * list_length + 1);

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
/*
	for(int i = 0; i < list_length; i++) {
		printf("Node:\t%c occurs %d times\n\n", list[i].letter, list[i].freq);
	}
*/
	treeNode* node_list = (treeNode*) ec_malloc(sizeof(treeNode) * list_length);

	for(int i = 0; i < list_length; i++) {
		node_list[i].data = &list[i];
		node_list[i].left = NULL;
		node_list[i].right= NULL;
	}
/*
	for(int i = 0; i < list_length; i++) {
		printf("Node:\t%c occurs %d times\n\n", node_list[i].data->letter, node_list[i].data->freq);
	}
*/
	//printf("\n");

	sortNodes(node_list, 0, list_length-1);

	for(int i = 0; i < list_length; i++)
		printf("Node:\t%c occurs %d times\n\n", node_list[i].data->letter, node_list[i].data->freq);
	printf("\n");

	for(int start_list = 0; start_list < list_length - 1;) {
		start_list = mergeNode(node_list, start_list);
		//printf("start_list: %d\n", start_list);
		sortNodes(node_list, start_list, list_length-1);

		for(int i = 0; i < list_length; i++)
			printf("Node:\t%c occurs %d times\n\n", node_list[i].data->letter, node_list[i].data->freq);
		printf("\n");

	}

	tree* huff = (tree*) ec_malloc(sizeof(tree));
	huff->head = &node_list[list_length-1];

	//printNode(huff->head);
	//printNode(huff->head->left);
	printNode(huff->head);
	printNode(huff->head->right);
	printNode(huff->head->right->right);
	if(!huff->head->left->left)
		printf("not null\n");

	//print_tree(huff->head);

	free(freq_arr);
	free(buffer);
	free(list);
	free(node_list);

	//free_tree(huff->head);
	//free(huff);
	
	return 0;
}