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
node* addLast(node* head, char data[]){
	node* newNode = createNode(data);
	if (!head) // head is empty
		return newNode;
	//head is not empty
	node* temp;
	for(temp =head;temp->next;temp=temp->next);
	temp->next = newNode;
	return head;
}
node* addAt(node* head, char data[], int position){
	if (position==0 || position == 1)
		return addFirst(head, data);
	//checking the following conditions
	//1 . the position should be > 1
	//2. The list is not empty
	//3. The list should contain atleast two elements
	if (position > 1 && head!=NULL && head->next !=NULL){
		node* temp = head;
		for (int i = 2; i<position && temp; i++)
			temp = temp->next;
		node* newNode = createNode(data);
		if (temp!=NULL && temp->next==NULL)
			temp->next = newNode;
		else if (temp!=NULL){
			newNode->next = temp->next;
			temp->next = newNode;
		}		
	}
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
node* deleteFirst(node* head){
	if (head) {//head is not empty
		node* temp=head;
		head = temp->next;
		free(temp);
	}
	return head;
}
node* deleteLast(node* head){
	if (head){
		if (!head->next){//list contains only one element
			free(head);
			return NULL;
		}
		//list contains more elements
		node *temp;
		for(temp=head; temp->next->next;temp=temp->next);
		free(temp->next);
		temp->next = NULL;
	}
	return head;
}
node* deleteAt(node* head, int position){
	if (position == 0 || position == 1)
		return deleteFirst(head);
	if (position>1 && head && head->next){
		node* temp= head;
		for (int i = 2; i<position && temp->next; i++, temp=temp->next);
		if (temp->next){ //checking temp is not pointing last node
			node* temp1 = temp->next;
			temp->next = temp1->next;
			free(temp1);
		}
	}
	return head;
}
//finding length of the list
int length(node* head){
	if (head)
		return 1+length(head->next);
}

int main(){
	node* head = NULL;
    head = addFirst(head,"Yeswant");
    head = addFirst(head,"Akash");
    head = addFirst(head, "Mukil");
    printList(head);
    head = addLast(head, "Guru");
    head = addAt(head,"Sri", 4);
    head = addAt(head, "Ahill", 6);
    head = addAt(head, "Amit", 9);
    printList(head);
    printf("\nDeletion\n");
    head = deleteFirst(head);
    printList(head);
    head = deleteLast(head);
    printList(head);
    head = deleteAt(head, 4);
    printList(head);
    head = deleteAt(head, 4);
    printList(head);
    printf("\nLength : %d\n", length(head));
    return 0;
}