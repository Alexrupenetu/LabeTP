#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int stack[100], queue[100];
int top=-1;

void push(int item)
{
	if(top==MAX_SIZE-1)
	{
		printf("Stiva plina");
		return;
	}
	stack[++top] = item;
}

int pop()
{
	if(top == -1)
	{
		printf("Stiva este goala");
		return -1;
	}
	return stack[top--];
}

void display()
{
	if(top == -1)
	{
		printf("Stiva este goala");
		return;
	}
	for(int i=top; i>=0; i--)
		printf("%d ", stack[i]);
	printf("\n");
}


int front=-1, rear=-1;
int queue[MAX_SIZE];

void enqueue(int item)
{
	if(rear == MAX_SIZE-1)
	{
		printf("Coada este plina");
		return;
	}
	if(front == -1) front = 0;
	queue[++rear] = item;
}

int dequeue()
{
	if(front == -1 || front>rear)
	{
		printf("Coada este goala");
		return -1;
	}
	return queue[front++];
} 

int main()
{
	push(10);
	push(20);
	push(30);
	display();
}
