#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*prev;
struct node*next;
};
struct node*head=NULL,*end=NULL;
static int size=0;
void insert_head(int data)
{
	struct node *node;
	node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->next=head;
	node->prev=NULL;
	if(head!=NULL)
	{
		head->prev=node;
		head=node;
	}
	else
	{
		head=node;
		end=node;
	}
	size++;
}
void insert_end(int data,int pos)
{
	int count=1;
	struct node *node,*temp;
	temp=head;
	node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->next=NULL;
	node->prev=NULL;
	if(end==NULL)
	{
		head=node;
		end=node;
	}
	else
	{
		node->prev=end;
		end->next=node;
		end=node;
	}
	size++;
}
void insert(int data,int pos)
{
	int count=1;
	struct node *node, *temp;
	temp = head;
	node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	do
	{
		if(count == pos)
		{
			node->next = temp->next;
			(temp->next)->prev = node;
			node->prev = temp;
			temp->next = node;
			size++;
			break;
		}
		else
		{
			count++;
			temp = temp->next;
		}
	}
	while(count<=pos);
}
void delete_head()
{
	struct node *temp;
	if(head!=NULL)
	{
		printf("Node Deleted.",head->data);
		temp=head;
		head=head->next;
		if(head!=NULL)
			head->prev=NULL;
		else
			end=NULL;
		free(temp);
		size--;
	}
	else
		printf("Empty Linked List!");
}
void delete_end()
{
	if(head == NULL)
	printf("Empty Linked List!");
	else
	{
		printf("Node deleted: %d", end->data);
		struct node *temp,*nxt_temp;
		temp = end;
		end = end->prev;
		if(end == NULL)
			head = NULL;
		else
			end->next = NULL;
		free(temp);
		size--;
	}
}
void delete(int pos)
{
	int count = 1;
	struct node *temp, *next_temp;
	temp = head;
	next_temp = temp->next;
	do
	{
		if(count==pos)
		{
			temp->next = next_temp->next;
			(next_temp->next)->prev = temp;
			printf("\nNode deleted: %d", next_temp->data);
			free(next_temp);
			size--;
			break;
		}
		else
		{
			count++;
			temp = next_temp;
			next_temp = next_temp->next;
		}
	}while(count<=pos);
}
void display_forward()
{
	if(head == NULL)
	printf("Empty Linked List!");
	else
	{
		struct node *link = head;
		printf("\t\t");
		while(link->next != NULL)
		{
			printf("%d ", link->data);
			link = link->next;
		}
		printf("%d\n", link->data);
	}
}
void display_reverse()
{
	if(end == NULL)
	printf("\nLinked List is Empty!!");
	else
	{
		struct node *link = end;
		printf("\t\t");
		while(link->prev != NULL)
		{
			printf("%d ", link->data);
			link = link->prev;
		}
		printf("%d\n", link->data);
	}
}
void search()
{
	int count = 1;
	if(head == NULL)
	printf("\nLinked List is Empty!!");
	else
	{
		int data;
		printf("Enter the number you want to search:");
		scanf("%d", &data);
		struct node *link = head;
		printf("\t\t");
		do
		{
			if(link->data==data)
			{
				printf("\\nThe number is found in the linked list!! %d and position is %d", link->data, count);
				return;
		}
		count++;
		link = link->next;
		}while(link != NULL);
		printf("\nThe number is not found in the linked list!!");
	}
}
void main()
{
	int ch,data,pos;
	do
	{
		printf("\nDoubly Linked List Menu\n1.Insert Head\n2.Insert End\n3.Insert at any Location\n4.Delete Head\n5.Delete End\n6.Delete at any Location\n7.Display Forward\n8.Display Reverse\n9.Search\n10.Exit\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:printf("Enter element to Insert:");
				scanf("%d",&data);
				insert_head(data);
				break;
			case 2:printf("Enter element to Insert:");
				scanf("%d",&data);
				insert_end(data);
				break;
			case 3:printf("Enter element to Insert:");
				scanf("%d",&data);
				printf("Enter the Position to Insert:");
				scanf("%d",&pos);
				if(pos<0 || pos>size)
					printf("\n\t\tInvalid Position!!");
				else if(pos == 0)
					insert_head(data);
				else if(pos == size)
					insert_end(data);
				else
				{
					insert(data, pos);
				}
				break;
			case 4:delete_head();
				break;
			case 5:delete_end();
				break;
			case 6:printf("Enter the position to Delete:");
				scanf("%d",&pos);
				if(pos<0 || pos>size)
					printf("\n\t\tInvalid Position!!");
				else if(pos == 0)
					delete_head();
				else if(pos == size-1)
					delete_end();
				else
					delete(pos);
				break;
			case 8:display_reverse();
				break;
			case 9:search();
				break;
			case 10:printf("Program Exiting...");
				break;
			default:printf("Wrong Choice!");
		}
		while(ch!=10);
	}
	while(ch!=10);
}
