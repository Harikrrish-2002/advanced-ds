#include<stdio.h>
#include<stdlib.h>
#define max 50
int q[max],rear=-1,front=-1,count=0;
void enqueue()
{
	int e;
	if(count==max)
	{
		printf("Queue Full.");
	}
	printf("Element To Insert:");
	scanf("%d",&e);
	if(front==-1)
	{
		front=0;
	}
	rear=rear+1%max;
	q[rear]=e;
	count++;
	printf("Element Inserted.");
}
void dequeue()
{
	if(count==0)
	{
		printf("Circular Queue Empty.");
	}
	printf("Dequeue Element=%d\n",q[front]);
	front=(front+1)%max;
	count--;
}
void display()
{
	if(count==0)
	{
		printf("Circular Queue Empty.\n");
	}
	int j=front;
	printf("Queue Elements are:\n");
	for(int i=0;i<count;i++)
	{
		printf("%d\n",q[j]);
		j=(j+1)%max;
	}
	printf("\n");
}
void main()
{
	int ch;
	while(1)
	{
		printf("\nCircular Queue Menu\n");
		printf("1.Enqueue:\n");
		printf("2.Dequeue:\n");
		printf("3.Display Queue:\n");
		printf("4.Exit:\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:exit(0);
			default:printf("Invalid Choice!");
		}
	}
}
