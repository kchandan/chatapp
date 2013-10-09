// Last in first out queue

#include <stdio.h>
#include <stdlib.h>

struct q {
	int data;
	struct q* link; 
};

typedef struct q Q;

void enter(Q **front,Q **rear,int val)
{
	if(*front ==NULL)
	{
		*front=(Q*)malloc(sizeof(Q));
		(*front)->data=val;
		(*front)->link=NULL;
		return;
	}
	Q *tmp=(Q*)*front;
	while(tmp->link)
	{
		tmp=tmp->link;
	}
	Q* t=(Q*)malloc(sizeof(Q));
	t->data=val;
	tmp->link=t;
	*rear=t;
}

void out(Q **front)
{
	if(*front == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	Q* tmp=(Q*)*front;
	*front=(*front)->link;
	free(tmp);
	return ;
}

void print_(Q **front,char *msg)
{
	Q *tmp=*front;
	printf(msg);
	while(tmp)
	{
		printf("Value =%d\n",tmp->data);
		tmp=tmp->link;
	}
}

int main()
{
	Q *front=NULL,*rear=NULL;
	int i=0;
	
	for(;i < 5;i++)
		enter(&front,&rear,i);

	print_(&front,"After enter\n");
	out(&front);

	print_(&front,"After out\n");
	return 0;
}

