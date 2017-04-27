#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char letter;
	int freq;
}pair;

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

pair *sortNodes(pair *list, size) {

	pair sorted_list[size];

	for(int i = 0; i < size; i++) {
		sorted_list[i] = 
	}

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

	list = (pair *) malloc(sizeof(pair) * char_count + 1);

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

	for(int i = 0; i < char_count; i++) {
		printf("Node %d:\n", i);
		printf("%c occurs %d times\n\n", list[i].letter, list[i].freq);
	}

	free(freq_arr);
	free(buffer);
	free(list);

	return 0;
}