#include "bst1.h"

int insert(struct node **root,int element)
{
	if(!(*root))
	{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));

newnode->data=element;
		*root=newnode;
		newnode->left=NULL;
		newnode->right=NULL;
		return 1;
	}
	else if(((*root)->data)>element)
	{
	  return insert(&((*root)->left),element);       }
	else if(((*root)->data)<element)
	{
	 return insert(&((*root)->right),element);
	}
	else
	{
	   printf("duplicates not allowed\n");
	   return 0;
	}
}

int inorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	inorder_traversal(root->left);
	printf("%d    ",root->data);
	inorder_traversal(root->right);
	return 1;
}

int preorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	printf("%d    ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	return 0;
}

int postorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d    ",root->data);
	return 1;
}

int search(struct node *root,int key,struct node **keyptr)
{
	static int a=0;
	if(!(root))
	{
		if(a)
		{
			printf("element not found\n");
		}
		else
		{
			printf("nothing element in the tree\n");
		}
		return 0;
	}
		
	else if((root->data) > key)
	{
	   	a++;
	return search(root->left,key,keyptr);     
     }
    else if((root->data) < key)
	{
	  	a++;
	  return search(root->right,key,keyptr);
	}
	else
	{
			a++;
		*keyptr=root;
		return 1;
	}
}

int findmin(struct node *root,int *minptr)
{
	if(!(root->left))
	{
		*minptr=root->data;
		return 1;
	}
	findmin(root->left,minptr);
	return 1;
}

int findmax(struct node *root,int *maxptr)
{
	if(!(root->right))
	{
		*maxptr=root->data;
		return 1;
	}
	findmax(root->right,maxptr);
	return 1;
}
	

int deletion(struct node **root,int element)
{
	static int a=0;
	if(!(*root))
	{
		if(a)
		{
			printf("element to be deleted hasn't found\n");
		}
		else
		{
			printf("no element is there in the tree");
		}
		return 0;
	}
	
	else if(((*root)->data) > element)
	{
	  return deletion(&((*root)->left),element);     
     }
    else if(((*root)->data) < element)
	{
	  return deletion(&((*root)->right),element);
	}
	else
	{
		if(!((*root)->left))
		{
			struct node *temp=*root;
			*root=(*root)->right;
			free(temp);
			return 1;
		}
		else if(!((*root)->right))
		{
			struct node *temp=*root;
			*root=(*root)->left;
			free(temp);
			return 1;
		}
		else
		{
			int min=0;
			findmin((*root)->right,&min);
			(*root)->data=min;
			deletion(&((*root)->right),min);
			return 1;
		}
	}
	a++;
}

int breadthfirst_traversal(struct node *root)
{
		if(!root)
		{
			return 0;
		}
		struct queue q;
		q.front=NULL;
		q.rear=NULL;
		enqueue(&q,root->data);
		int a;
		struct node *temp;
		while(q.front)
		{
			dequeue(&q,&a);
			printf("%d  ",a);
			search(root,a,&temp);
			if(temp->left)
			{
			enqueue(&q,(temp->left)->data);
			}
			if(temp->right)
			{
		     enqueue(&q,(temp->right)->data);
			}
		}
		return 0;
}

int enqueue(struct queue *q,int element)
{
	struct queuenode *newnode=(struct queuenode *)malloc(sizeof(struct queuenode));
	if(!(newnode))
	{
		printf("out of memory\n");
		return 0;
	}
	newnode->data=element;
	 newnode->next=NULL;
	if(!(q->front))
	{
		q->front=newnode;
		q->rear=newnode;
		return 1;
	}
	(q->rear)->next=newnode;
	 q->rear=newnode;
	return 1;
}
int dequeue(struct queue * q,int *ptr)
{
	if(!q->front)
	{
		printf("empty queue\n");
		return 1;
	}
	*ptr=(q->front)->data;
	struct queuenode *temp=q->front;
	q->front=(q->front)->next;
	if(!q->front)
	{
		q->rear=NULL;
	}
	free(temp);
	return 1;
}