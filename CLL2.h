#include "CLL1.h"

int init(struct node **tail)
{
	*tail=NULL;
	return 1;
}
int insertbyelement(struct node **tail,int preelement,int element)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("out of memory\n");
		return 0;
	}
	struct node *pre=NULL;
	newnode->data=element;
	if(*tail==NULL)
	{
		newnode->next=newnode;
		*tail=newnode;
		return 1;
	}
	pre= (*tail)->next;
	do
	{
		if(pre->data==preelement)
		{
			newnode->next=pre->next;
			pre->next=newnode;
			if(pre==(*tail))
			{
				*tail=newnode;
			}
			return 1;
		}
		pre=pre->next;
	}
	while(pre!= (*tail)->next);
	printf("invalid predecessor element");
	free(newnode);
	return 0;
}
int search(struct node *tail,int element,struct node **keyptr)
{
	if(tail==NULL)
	{
		printf("empty list\n");
		return 0;
	}
	struct node *iter=tail->next;
	do
	{
		if(iter->data==element)
		{
			printf("element found\n");
			*keyptr=iter;
			return 1;
		}
		iter=iter->next;
		}
		while(iter!= tail->next);
		printf("element not found\n");
		*keyptr=NULL;
		return 0;
}
int traverse(struct node *tail)
{
     	if(tail==NULL)
     	{
	    	printf("empty list\n");
	    	return 0;
      	}
      	struct node *temp= tail->next;
      	do
      	{
      		printf("%d->",temp->data);
      		temp=temp->next;
      	}
      	while(temp!= tail->next);
      	printf("\n");
      	return 1;
}
int deleteelement(struct node **tail,int element)
{
		if(*tail==NULL)
	    {
		return 1;
     	}
     	struct node *pre=*tail;
     	struct node *iter=pre->next;
     	if(pre==iter)
     	{
     		free(iter);
     		return 1;
     	}
     	
     	do
     	{
     		if(iter->data==element)
     		{
     			pre->next=iter->next;
     			if(iter==(*tail))
     			{
     				*tail=pre;
     			}
     			free(iter);
     			return 1;
     		}
     		pre=iter;
     		iter=iter->next;
     	}
     	while(iter!= (*tail)->next);
     	printf("element to be deleted is not found\n");
     	return 0;
}