//Program to implement stack operations
#include <stdio.h>
#include <stdlib.h>
typedef enum boolean {false, true} boolean;
//typedef enum boolean {true=1, false=0} boolean;
typedef struct Book{
	int id;
	char title[30];
	double price;
}book;
typedef struct Stack{
	int capacity;
	int top;
	book *books;
}stack;
stack* createStack(int max){
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->capacity = max;
	temp->top = -1; //stack is empty
	temp->books = (book*)malloc(sizeof(book)*max);
	return temp;
}
boolean isFull(stack *st){
//	if (st->top +1 == st->capacity)
//		return true;
//	return false;
	return st->top +1 == st->capacity;
}
boolean isEmpty(stack *st){
	return st->top == -1;
}
boolean push(stack *st, book b){
	if (isFull(st))
		return false;
//	st->top++;
//	st->books[st->top] = b;
	st->books[++st->top] =b;
	return true;
}
book* pop(stack *st){
	if (isEmpty(st))	
		return NULL;
	return &st->books[(st->top)--];
}
book* peek(stack *st){
	if (isEmpty(st))	
		return NULL;
	return &st->books[st->top];
}
int stackSize(stack *st){
	return st->top+1;
}
void printMenu(){
	printf("\nStack operations demo\n");
	printf("*********************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Stack Size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");
}
book getBook(){
	book b;
	printf("Book ID : ");
	scanf("%d", &b.id);
	printf("Book Title : ");
	scanf("\n%[^\n]s", b.title);
	printf("Book Price: ");
	scanf("%lf", &b.price);
	return b;
}
void printBook(book b){
	printf("Book ID : %d\n", b.id);
	printf("Book Title : %s\n", b.title);
	printf("Book Price: %.2lf\n", b.price);
}

int main(){
	int size;
	scanf("%d", &size);
	stack *myStack = createStack(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (!isFull(myStack) && push(myStack, getBook()))
					printf("Pushed....\n");
				else
					printf("Stack Overflow..\n");
				break;
			case 2:{
				book* b = pop(myStack);
				if(b)
					printBook(*b);
				else
					printf("Stack Underflow....\n");					
				break;
			}
			case 3:{
				book* b = peek(myStack);
				if(b)
					printBook(*b);
				else
					printf("Stack Underflow....\n");					
				break;
			}
			case 4:
				printf("Stack Size : %d\n", stackSize(myStack));
				break;
			default:
				printf("Thank you so much for being very very silent in the class!");
				return 0;
		}
	}	
	
	return 0;
}