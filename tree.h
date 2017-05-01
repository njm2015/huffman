/*
* Helper functions for encoding the data using huffman encoding.
*
* Also includes tree, treeNode, and pair structs
*/

/*
* @author Nathaniel Murphy -- Math and CompSci at UIUC
*
* This file includes helper functions and structs for encoder.c
* trees and treeNodes are defined here as well as their helpers
*/

#ifndef TREE_H
#define TREE_H

/*
* Struct for storing final encoding and character
*/
typedef struct _pair pair;
struct _pair {
	char c;
	char huff_code[10];
};

/*
* treeNodes make up the huffman tree. Store character, freqency of that character, and left/right treeNodes
*/
typedef struct _treeNode treeNode;
struct _treeNode {
	char letter;
	int freq;
	treeNode* left;
	treeNode* right;
};

/*
* tree struct. Only stores head of tree
*/
typedef struct _tree tree;
struct _tree {
	treeNode* head;
};

/*
* Standard usage fucntion -- called when less than 2 arguments
* @param prog_name -- ./encoder
*/
void usage(char* prog_name);

/*
* Called when error occurs, exits afterward
* @param message -- error message to be displayed
*/
void fatal(char* message);

/*
* An error checking malloc function.
* Exits if pointer is NULL.
* @param size -- size of memory to be allocated
*/
void* ec_malloc(unsigned int size);

/*
* Initializes freq_arr with 0's.
* @param freq_arr -- array to be initialized
* @param size -- size of freq_arr
*/
void initFreqArr(int* freq_arr, int size);

/*
* Indexes the frequences of each character in buffer.
* @param buffer -- string to be indexed
* @param freq_arr -- frequency array of int's
*/
void indexFreq(char* buffer, int* freq_arr);

/*
* Returns how many distinct characters appeared in buffer
* @param freq_arr -- frequency array for buffer
* @param size -- size of of freq_arr
* @return number of distinct characters
*/
int getListLength(int* freq_arr, int size);

/*
* Swaps nodes at indices a and b of node_list[].
* @param node_list[] -- array of treeNode pointers
* @param a,b -- respective indices to be swapped
*/
void swap(treeNode* node_list[], int a, int b);

/*
* Sorts nodes from indices lo to hi. When finished, node with lowest 
* frequency will be at index lo in node_list[].
* @param node_list[] -- array of treeNode pointers
* @param lo -- lowest index to sort
* @param hi -- highest index to sort
*/
void sortNodes(treeNode* node_list[], int lo, int hi);

/*
* Creates new parent treeNode for treeNodes node_list[start_list]
* and node_list[start_list+1].
* @param node_list[] -- array of treeNode pointers
* @param start_list -- lowest index in node_list to merge
*/
int mergeNode(treeNode* node_list[], int start_list);

/*
* Traverses tree and frees each treeNode.
* @param head -- pointer to head of tree
* @return new start_list position
*/
void freeTree(treeNode* head);

/*
* Prints one treeNode.
* @param head -- node to be printed
*/
void printNode(treeNode* head);

/*
* Prints all the nodes of a tree.
* @param head -- pointer to head of tree
*/ 
void printTree(treeNode* head);

/*
* Traverses to each leaf of the tree and when assigns the
* corresponding code to its character which it stores in
* code_list.
* @param head -- head of tree
* @param c[] -- current traversal of tree (in 0's and 1's)
* @param code_list -- array of character-code pairs
*/
void findLetter(treeNode* head, char c[], pair* code_list);

/*
* Takes original buffer and encodes it using generated huffman encoding
* @param ret_buffer -- stores encoded message
* @param buffer -- original buffer user entered
* @param code_list -- array of character-code pairs
* @param list_length -- length of code_list
*/
void encode(char* ret_buffer, char* buffer, pair* code_list, int list_length);

#endif