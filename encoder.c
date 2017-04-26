#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char letter;
	int freq;
}

struct nodelist {
	node* list;
}

void usage(char* prog_name) {
	printf("Enter single line of text  < usage for %s >\n", prog_name);
	exit(0);
}

int main(int argc, char* argv[]) {

	if(argc < 2)
		usage(argv[0]);

	int* freq_arr;
	int* next_arr;

	freq_arr = (int*) malloc(sizeof(int) * 30 + 1);

	for(int i = 0; i < 31; i++)
		freq_arr[i] = 0;

	char* buffer;

	buffer = (char*) malloc(sizeof(char) * 80 + 1);

	strcpy(buffer, argv[1]);

	for(int i = 0; i < (int)strlen(buffer) + 1; i++) {
		if(buffer[i] == '.')
			freq_arr[26]++;
		else
			freq_arr[buffer[i]-97]++;
	}

	for(int i = 0; i < 31; i++)
		printf("%d\n", freq_arr[i]);

	free(freq_arr);

	return 0;
}