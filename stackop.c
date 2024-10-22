#include <stdio.h>
#include <stdlib.h>
#define MAX 50 
int stack[MAX], top = -1; 
void push() 
{
	int e;
	if (top == MAX - 1) 
	{
		printf("Stack Overflow!\n");
		return;
	}
	printf("Enter the element to be pushed:");
	scanf("%d", &e);
	top++; 
	stack[top] = e; 
	printf("%d pushed to the stack\n", e);
}
void pop()
{
	if (top == -1) 
	{
		printf("Stack Underflow.\n");
		return;
	}
	printf("Popped element: %d\n", stack[top]);
	top--; 
}
void display()
{
	int i;
	if (top == -1) 
	{
		printf("Stack is empty.\n");
		return;
	}
	printf("Stack elements are:\n");
	for (i = top; i >= 0; i--) 
	{
		printf("%d\n", stack[i]);
	}
}
int main() 
{
	int ch;
	while (1) 
	{
		printf("\nSTACK MENU\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) 
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:
				printf("Invalid choice!\n");
		}
	}
	return 0;
}
