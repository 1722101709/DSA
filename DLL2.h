#include "DLL1.h"

int init(struct node **head,struct node **tail)
{
	*head=*tail=NULL;
	return 1;
}
int insertbypos(struct node **head,struct node **tail,int pos,int element)
{
	struct node *newnode= (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("out of memory\n");
		return 0;
	}
	newnode->data=element;
	struct node *pre=NULL;
	struct node *iter=*head;
	for(int i=1;i<pos && iter!=NULL;i++)
	{
		pre=iter;
		iter=iter->next;
	}
	if(pre==NULL)
	{    
	     newnode->next=iter;
	  	newnode->prev=NULL;
	  	*head=newnode;
	     if(iter==NULL)
	     {
	  	
	  	*tail=newnode;
	       }
   	  else
	    {
	  	iter->prev=newnode;
	    }
	    return 1;
	}
	else
	{     
	          newnode->next=iter;
	  		newnode->prev=pre;
	  		pre->next=newnode;
	  	if(iter==NULL)
	  	{
	  		
	  		*tail=newnode;
	  	}
	  	else
	  	{
	  		iter->prev=newnode;
	  	}
	  	return 1;
	}
}
int fwdtraversal(struct node *head)
{
	  	printf("forward traverse:-  ");
	  	struct node *iter=NULL;
	  	if(head==NULL)
	  	{
	  		printf("empty list\n");
	  		return 0;
	  	}
	  	iter=head;
	  	while(iter!=NULL)
	  	{
	  	  printf("%d<=>",iter->data);
	  	  iter=iter->next;
	  	}
	  	printf("\n");
	  	return 1;
}
  int bwdtraversal(struct node *tail)
{
	  	printf("backward traverse:-  ");
	  	struct node *iter=NULL;
	  	if(tail==NULL)
	  	{
	  		printf("empty list\n");
	  		return 0;
	  	}
	  	iter=tail;
	  	while(iter!=NULL)
	  	{
	  	  printf("%d<=>",iter->data);
	  	  iter=iter->prev;
	  	}
	  	printf("\n");
	  	return 1;
}
int search(struct node *head,int element,struct node **keyptr)
{
	if(head==NULL)
	{
		printf("empty list\n");
		return 0;
	}
	struct node *iter=head;
	while(iter!=NULL)
	{
		if(iter->data==element)
		{
			printf("key found\n");
			*keyptr=iter;
			return 1;
		}
		iter=iter->next;
	}
	printf("key not found\n");
	return 0;
}
	int deletebypos(struct node **head,struct node **tail,int pos)
{
	if(*head==NULL)
	{
		printf("empty list\n");
		return 0;
	}
	struct node *pre=NULL;
	struct node *iter=*head;
	for(int i=1;i<pos && iter!=NULL;i++)
	{
		pre=iter;
		iter=iter->next;
	}
	if(pre==NULL)
	{
		if(*head==*tail)
		{
			*head=*tail=NULL;
		}
		else
		{
			*head=iter->next;
			(*head)->prev=NULL;
		}
	}
	else
	{
			if(iter==*tail)
			{
				*tail=pre;
				pre->next=NULL;
			}
			else
			{
				if(iter==NULL)
				{
					printf("invalid position\n");
					return -1;
				}
				else
				{
					pre->next=iter->next;
					iter->next->prev=pre;
				}
			}
	}
			free(iter);
		return 1;
	}
  int deleteelement(struct node **head,struct node **tail,int element)
{
	if(*head==NULL)
	{
		printf("empty list\n");
		return 0;
	}
	struct node *pre=NULL;
	struct node *iter=*head;
	while(iter!=NULL)
	{
		if(iter->data==element)
		{
			break;
		}
		pre=iter;
		iter=iter->next;
	}
	if(pre==NULL)
	{
		if(*head==*tail)
		{
			*head=*tail=NULL;
		}
		else
		{
			*head=iter->next;
			(*head)->prev=NULL;
		}
	}
	else
	{
		if(*tail==iter)
		{
			*tail=pre;
			pre->next=NULL;
		}
		else
		{
			if(iter==NULL)
			{
				printf("invalid position\n");
				return -1;
			}
			else
			{
				pre->next=iter->next;
				iter->next->prev=pre;
			}
		}
	}
  free(iter);
  return 1;
}
int destroy(struct node **head,struct node **tail)
{
	printf("---->after destructing list<-----\n");
	if(*head==NULL)
	{
		return 1;
	}
	while(*head!=NULL)
	{
		deleteelement(head,tail,(*head)->data);
	}
	return 0;
}