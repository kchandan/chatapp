#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* next;
    int data;
};

typedef struct node Node;

void create_node(int val,Node** head)
{
		*head=(Node*)malloc(sizeof(Node));
//		*head->data=val;
}

void append_node(int val, Node** head )
{
	if(*head == NULL)
	{
			printf("No node\n");
			return;
	} 
	Node *tmp,*right;
	right=(Node*)*head;

	while(right->next !=NULL){
	//	fprintf(stderr,"Inside append = %d\n",right->data);
		right=right->next;
	}
	tmp=(Node*)malloc(sizeof(Node));
	right->next=tmp;
	tmp->next=NULL;
	tmp->data=val;
}

void print_node(Node **head)
{
	if(*head == NULL)
	{
			printf("No node to print\n");
			return ;
	}
	int count=0;
	Node *my=(Node*)*head;
	do
	{
		printf("Node val=%d,count=%d\n",my->data,count);
		my=my->next;count++;
	}while(my !=NULL);
}

void delete_node(int i, Node **head)
{
	if(*head == NULL)
	{
		printf("No node to delete\n");
		return;
	}
	Node* prev,*tmp;
	tmp=(Node*)*head;

	while(tmp !=NULL)
	{
		if(tmp->data == i)
		{
			if(tmp==*head)
			{
				*head=tmp->next;
				free(tmp);return;
			}
			else
			{
				prev->next=tmp->next;
				free(tmp);return;
			}
			
		}
		else
		{
			prev=tmp;
			tmp=tmp->next;
		}
	}

}

void insert_before(int i, Node **head,int val)
{	
	if(*head == NULL)
	{
		printf("No node to delete\n");
		return;
	}
	Node* prev,*tmp,*new;
	tmp=(Node*)*head;
	while(tmp!=NULL)
	{
		if(tmp->data == i)
		{
			new=(Node*)malloc(sizeof(Node));
			if(tmp == *head)
			{
				new->next=*head;
				new->data=val;
				*head=new;
				return;
			}
			else
			{
				new->data=val;
				prev->next=new;
				new->next=tmp;
				return;
			}
		}
		else
		{
			prev=tmp;
			tmp=tmp->next;
		}
	}
}

int init_node(int i,Node **head)
{
}

int main(void)
{
	int i=1;
	Node* head=(Node*)malloc(sizeof(Node));
//	init_node(1,&head);
	head->data=0;head->next=NULL;
	for(;i < 6;i++)
		append_node(i,&head);
	print_node(&head);
	delete_node(5,&head);
	printf("\nAfter delete\n");
	print_node(&head);
	insert_before(0,&head,10);
	printf("\nAfter Insert\n");
	print_node(&head);

    return 0;
}



