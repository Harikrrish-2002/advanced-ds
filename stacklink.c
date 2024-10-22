#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node* start = NULL;
struct node* getnode()
{
	int item;
	printf("Enter The Value to Insert:");
	scanf("%d",&item);
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	printf("Value Inserted.\n");
	if (new_node == NULL) 
	{
		printf("Memory allocation failed!\n");
		exit(1); 
		new_node ->data = item; 
		new_node ->link = NULL;
		return new_node;
	}
}
void ihead()
{
	struct node*new_node=getnode();
	if(start==NULL)
	{
		start=new_node;
	}
	else
	{
		struct node*ptr=start;
		while(ptr->link !=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new_node;
	}
}
void dhead()
{
	if(start==NULL)
	{
		printf("Node Empty");
	}
	else
	{
		struct node*ptr=start;
		start=start->link;
		printf("Node Deleted.");
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\nSTACK LINKEDLIST MENU\n");
		printf("1.Insert at Top.\n");
		printf("2.Delete Top.\n");
		printf("3.Exit.\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ihead();
				break;
			case 2:dhead();
				break;
			case 4:exit(0);
			default:printf("Invalid Choice!\n");
		}
	}
}
