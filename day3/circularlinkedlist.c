//Program to implement circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char value;
	struct Node *next;
}node;
node* createNode(char data){
	node* temp = (node*)malloc(sizeof(node));
	temp->value = data;
	temp->next = NULL;
	return temp;
}

node* addFirst(node* tail, char data){
	node* newNode = createNode(data);
	if (tail){
		//tail is not empty
		newNode->next = tail;
		tail->next = newNode;
	}
	else{
		//tail is empty
		newNode->next = newNode;
		tail=newNode;
	}
	return tail;
}
node* addLast(node* tail, char value){
	node *newNode = createNode(value);
	if (tail){
		newNode->next = tail->next;
		tail->next = newNode;
	}else
		newNode->next = newNode;
	tail = newNode;
	return tail;
}
node* deleteFirst(node* tail){
	if (tail){
		//tail is not empty
		//checking whether list contains only one element
		if (tail->next == tail){
			free(tail);
			return NULL;
		}
		node* temp = tail->next ;
		tail->next = temp->next;
		free(temp);
	}
	return tail;
}
node* deleteLast(node* tail){
	//complete the code
	return NULL;
}
void printList(node* tail){
	if (tail){
		printf("\n[");
		for (node* temp = tail->next; temp != tail; temp=temp->next)
			printf("'%c',", temp->value);
		printf("'%c']", tail->value);
	}
	else
		printf("\n[]");		
}

int main(){
	node* tail = NULL;
	tail = addFirst(tail, 'A');
	tail = addFirst(tail, 'C');
	tail = addLast(tail, 'B');
	tail = addLast(tail, 'D');
	printList(tail);
	tail = deleteFirst(tail);
	printList(tail);
	
	return 0;
}