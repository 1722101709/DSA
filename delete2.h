#include"delete1.h"
#include"stddef.h"
int init(struct node **head)
{
	*head=NULL;
	return 0;
}
int insert(struct node **head,int element)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("out of memory\n");
		return -1;
	}
	newnode->data=element;
	struct node *pre=NULL;
	struct node *iter=*head;
	while(iter!=NULL && iter->data>element)
	{
		pre=iter;
		iter=iter->next;
	}
		newnode->next=iter;
		if(pre==NULL)
		{
			*head=newnode;
			return 1;
		}
		else
		{
			pre->next=newnode;
			return 1;
		}
	}
	int traversal(struct node *head)
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("NULL");
		return 0;
	}