#include "splay1.h"

int insert(struct node **root,int element)
{
	if(!(*root))
	{
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=element;
		newnode->left=NULL;
		newnode->right=NULL;
		*root=newnode;
		return 1;
	}
	else if((*root)->data > element)
	{
		insert(&((*root)->left),element);
		if(((*root)->left)->data == element)
		{
			zig(root,0);
		}
		else
		{
			zig_zag(root,0);
		}
			return 1;
	}
	else if((*root)->data < element)
	{
		insert(&((*root)->right),element);
		if(((*root)->right)->data == element)
		{
			zig(root,1);
		}
		else
		{
			zig_zag(root,1);
		}
			return 1;
	}
	else
	{
		printf("duplicates are not allowed\n");
         return 0;
     }
}

int zig(struct node **root,int flag)	
{
	if(flag)
	{
		struct node *temp=(*root)->right;
		(*root)->right=((*root)->right)->right;
	 struct node *iter= ((*root)->right)->left;
	     ((*root)->right)->left=temp;
	     temp->right=iter;
	     return 1;
	}