#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node*link;
};
struct Node* start=NULL;
struct Node* getNode()
{
	int item;
	printf("Enter The Value to Insert:");
	scanf("%d",&item);
	struct Node*new_Node=(struct Node*)malloc(sizeof(struct Node));
	if(new_Node==NULL)
	{
		printf("Allocation Failed!");
		exit(1);
		new_Node->data=item;
		new_Node->link=NULL;
		return new_Node;
	}
}
void insertTail() 
{
	struct Node* new_Node = getNode(); 
	if (start == NULL) 
	{
	start = new_Node;
	} 	
	else 
	{
		struct Node* ptr = start; 
		while (ptr->link != NULL) 
		{
			ptr = ptr->link;
		}
		ptr->link = new_Node;
	}
}
void deleteAtHead() 
{
	if (start == NULL) 
	{
		printf("List is empty.\n");
	} 
	else 
	{
		struct Node* ptr = start; 
		start = start->link; 
		free(ptr); 
		printf("Head node deleted.\n");
	}
}
void main()
{
	int ch;
	printf("\nQUEUE LINKEDLIST MENU\n");
	printf("1.Insert at Tail.\n");
	printf("2.Delete Head.\n");
	printf("3.Exit\n");
	printf("Enter Your Choice.\n");
	switch(ch)
	{
		case 1:insertTail();
			printf("Inserted At Tail.\n");
			break;
		case 2:deleteAtHead();
			printf("Deleted from Front.\n");
			break;
		case 3:exit(0);
		default:printf("Invalid Choice!\n");
	}
}
