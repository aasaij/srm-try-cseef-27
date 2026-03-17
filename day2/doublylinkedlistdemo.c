//Program to demonstrate doubly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	struct Node *prev;
	char value;
	int data;
	struct Node *next;
}node;
node* createNode(char element){
	node* temp = (node*)malloc(sizeof(node));
	temp->value = element;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}
node* addFirst(node* head, char element){
	node* newNode = createNode(element);
	if (!head)
		return newNode;
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return head;
}
node *addLast(node* head, char element){
	node* newNode = createNode(element);
	if (!head) // head is empty
		return newNode;
	node* temp;
	for (temp = head;temp->next; temp = temp->next);
	temp->next = newNode;
	newNode->prev = temp;
	return head;
}
node* addAt(node* head, char element, int position){
	//Complete the code
	return NULL;
}

node* deleteFirst(node* head){
	if (head){
		if (head->next==NULL){//list contains only one element
			free(head);
			return NULL;
		}
		node* temp = head;
		head = temp->next;
		head->prev = NULL;
		free(temp);
	}
	return head;
}
node* deleteLast(node* head){
	//Complete the code
	return NULL;
}
node* deleteAt(node* head, int position){
	//Complete the code
	return NULL;
}
void printList(node *head){
	if (head){
		printf("\nForward Traversal : [");
		node* temp;
		for (temp = head; temp->next!=NULL; temp = temp->next)
			printf("'%c',", temp->value);
		printf("'%c']", temp->value);
		printf("\nBackward Traversal : [");
		for (; temp->prev!=NULL; temp = temp->prev)
			printf("'%c',", temp->value);
		printf("'%c']", temp->value);	
	}
	else
		printf("\n[]");
}

int main(){
	node *root = NULL;
	root = addFirst(root, 'A');
	root = addLast(root, 'B');
	root = addFirst(root, 'C');
	root = addLast(root, 'D');
	printList(root);
	root = deleteFirst(root);
	printList(root);
	return 0;
}