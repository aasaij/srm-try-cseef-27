//Program to implement the circular queue
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
typedef enum boolean {false, true} bool;
typedef struct Emplyee{
	int eid;
	char name[30];
	double salary;
}employee;

typedef struct Queue{
	int capacity;
	int front;
	int rear;
	employee *emps;
}queue;

queue* createQueue(int qsize){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = qsize;
	temp->front = -1;
	temp->rear = -1;
	temp->emps = (employee*)malloc(sizeof(employee)*qsize);
	return temp;
}
bool isFull(queue* q){
	return q->rear+1 == q->capacity && q->front == 0 ||
		q->rear+1 == q->front;	
}

bool isEmpty(queue *q){
	return q->front == -1 && q->rear == -1;
}
void enqueue(queue* q, employee e){
	if (q->front == -1) q->front = 0;
//		q->rear++;
//		q->emps[q->rear] = e;
//		q->emps[++q->rear] = e;
	q->rear = (q->rear + 1) % q->capacity;
	q->emps[q->rear] = e;
}
bool dequeue(queue *q){
	if (!isEmpty(q)){
		//checking whether the queue has only one element or not
		if (q->front == q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else
			q->front = (q->front + 1) % q->capacity;
		return true;
	}
	return false;
}
int queueSize(queue *q){
	if (q->front == -1)
		return 0;
	return q->rear - q->front + 1;
}
employee *front(queue *q){
	if (!isEmpty(q))
		return &q->emps[q->front];
	return NULL;
}
employee *rear(queue *q){
	if (!isEmpty(q))
		return &q->emps[q->rear];
	return NULL;
}

void printMenu(){
	printf("\nQueue Operations Demo\n");
	printf("*********************\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display front\n");
	printf("4. Display rear\n");
	printf("5. Queue size\n");
	printf("6. Exit\n");
	printf("Enter your choice : ");
}
employee getEmployee(){
	employee e;
	printf("Employee ID   : ");
	scanf("%d", &e.eid);
	printf("Employee Name : ");
	scanf("\n%[^\n]s", e.name);
	printf("Salary        : ");
	scanf("%lf", &e.salary);
	return e;
}
void printEmployee(employee e){
	printf("Employee ID   : %d\n", e.eid);
	printf("Employee Name : %s\n", e.name);
	printf("Salary        : %.2lf\n", e.salary);
}
int main(){
	queue *myQueue = NULL;
	int size;
	scanf("%d", &size);
	myQueue = createQueue(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
//				printf("%s\n", !isFull(myQueue) && enqueue(myQueue, getEmployee()) ?"Enqueued...":"Queue is full!");
				if (!isFull(myQueue)){
					enqueue(myQueue, getEmployee());
					printf("Enqueued..\n");
				}
				else
					printf("Queue is full!");
				break;
			case 2:
				if(dequeue(myQueue))
					printf("Dequeued...\n");
				else
					printf("Queue is Empty!\n");
				break;
			case 3:{
				employee *e = front(myQueue);
				if (e)
					printEmployee(*e);
				else
					printf("Queue is Empty!\n");
				break;
			}
			case 4:{
				employee *e = rear(myQueue);
				if (e)
					printEmployee(*e);
				else
					printf("Queue is Empty!\n");
				break;
			}
			case 5:
				printf("Queue Size : %d", queueSize(myQueue));
				break;
			default:
				printf("Thank you so much for being very very interactive in the class...\n");
				exit(0);				
		}	
	}
	return 0;
}