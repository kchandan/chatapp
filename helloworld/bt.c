#include <stdio.h>
#include <stdlib.h>

struct bt {
	int m_key;
	struct bt *left;
	struct bt *right;
};

typedef struct bt Bt;

void insert(Bt **leaf,int key)
{
	Bt *tmp=NULL;
	if(*leaf ==NULL){
		printf("Inside NULL\n");
		tmp=(Bt*)malloc(sizeof(Bt));
		tmp->left= tmp->right=NULL;
		tmp->m_key=key;
		return;
	}
	if( key < (*leaf)->m_key){
		printf("In left \n");
		insert(&(*leaf)->left,key);
	}else if( key > (*leaf)->m_key) {
		printf("In right\n");
		insert(&(*leaf)->right,key);
	}
	
	return;
}

Bt* search(Bt **leaf, int val)
{
	if(NULL == *leaf)
	{
		return NULL;
	}
	if(val == (*leaf)->m_key)
	{
		return *leaf;
	}
	else if (val < (*leaf)->m_key)
	{
		search(&(*leaf)->left,val);
	} 
	else if (val < (*leaf)->m_key)
	{
		search(&(*leaf)->right,val);
	}
	return NULL;
}

void print_pre(Bt **leaf)
{
	if(*leaf)
	{
		printf("%d\n",(*leaf)->m_key);
		print_pre(&(*leaf)->left);
		print_pre(&(*leaf)->right);
	}
}

int
main()
{
	Bt *root=(Bt*)malloc(sizeof(Bt));
	int i=1;
	root->m_key=20;
	root->left=NULL;root->right=NULL;
	//for(i=0;i<1;i++)
		insert(&root,i);
	print_pre(&root);
	return 1;	
}
