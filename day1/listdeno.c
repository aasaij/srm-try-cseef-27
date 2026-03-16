//Program to demonstrate singly linked list
#include <stdio.h>
#include <string.h>
//defining the structure for Node
typedef struct Node{
	char name[30]; // 30
	struct Node *next; // 8
}node;

//typedef struct Node node;
int main(){
	node *x = (node *)malloc(sizeof(node));
	node *y = (node *)malloc(sizeof(node));
	strcpy(x->name,"Yeswant");
	
	strcpy(y->name,"Akash");
	
	x->next = &y;
	y->next = NULL;
	return 0;
}

//Dynamic Memory allocation
malloc()
	
calloc()
realloc()
free()

		functions protype stdlib.h
			void* malloc(size_t numBytes);
			void* calloc(size_t numBlocks, size_t sizeOfBlock);
			void* realloc(void* oldBlock, size_t newSizeInBytes);
			
			void free(void* block);
			


