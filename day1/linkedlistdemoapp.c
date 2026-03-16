#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
    char name[33]; // 30
    struct Node *next; // 8
}node;
node* createNode(char data[]){
	node* temp =(node*) malloc(sizeof(node));
	strcpy(temp->name, data);
	temp->next = NULL;
	return temp;
}
node* addFirst(node* head, char data[]){
	node* newNode = createNode(data);
	newNode->next = head;
	head = newNode;	
	return head;
}
void printList(node* head){
	if (head){
		//head is not empty
		printf("\n[");
		node* temp;
		for (temp = head; temp->next; temp=temp->next)
			printf("\"%s\",", temp->name);		
		printf("\"%s\"]", temp->name);		
	}
	else
		printf("\n[]");
}


int main(){
	node* head = NULL;
//    head = addFirst(head,"Yeswant");
//    head = addFirst(head,"Akash");
//    head = addFirst(head, "Mukil");
    printList(head);
    return 0;
}