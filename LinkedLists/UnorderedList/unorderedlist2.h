#include"list1.h"
#include"stddef.h"
int init(struct node **head)
{
	*head=NULL;
	return 0;
}
int insert(struct node **head,int data,int pos)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *pre=NULL;
	if(newnode==NULL)
	{
		printf("out of memory\n");
		return 0;
	}
	newnode->data=data;
	if(pos==1)
	{
		newnode->next=*head;
		*head=newnode;
		return 0;
	}
	pre=*head;
	for(int i=1;i<pos-1 && pre!=NULL;i++)
	{
		pre=pre->next;
	}
	if(pre==NULL)
		{
			printf("invalid position");
			return 0;
		}
		else
		{
			newnode->next=pre->next;
			pre->next=newnode;
			return 0;
		}
}
int traversal(struct node *head)
{
	if(head==NULL)
	{
		printf("empty list");
		return 0;
	}
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("NULL \n");
	return 0;
}
int searchlist(struct node *head,int key,struct node **keyptr)
{
	if(head==NULL)
	{
		printf("empty list");
		return -1;
	}
	struct node *temp=head;
	 while(temp!=NULL)
	 {
	 	if(temp->data==key)
	 	{
	 		keyptr=temp;
	 		return 1;
	 	}
	 	temp=temp->next;
	 }
	 return 0;
}
	int deletebypos(struct node **head,int element,int pos)
	{
		if(head==NULL)
		{
			printf("list is empty");
			return -1;
		}
		struct node *pre=NULL;
		struct node*iter=*head;
		
		for(int count=1;count<pos && iter!=NULL;count++)
		{
			pre=iter;
			iter=iter->next;
		}
		if(iter==NULL)
		{
			printf("invalid position");
			return 0;
		}
		else
		{
			if(pre==NULL)
			{
				*head=iter->next;
			}
			else
			{
				pre->next=iter->next;
			}
			free(iter);
			return 1;
		}
			return 0;
	}
	int deletebyelement(struct node **head,int element)
	{
		if(head==NULL)
		{
			printf("list is empty");
			return -1;
		}
		struct node *pre=NULL;
		struct node *iter=*head;
		while(iter->data!=element && iter!=NULL)
		{
			pre=iter;
			iter=iter->next;
		}
		if(iter==NULL)
		{
			printf("element not found");
			return 0;
		}
		else
		{
			if(pre==NULL)
			{
				*head=iter->next;
			}
			else
			{
				pre->next=iter->next;
			}
			free(iter);
			return 1;
		}
	}