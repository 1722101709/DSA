#include<stdio.h>
#include<stdlib.h>
#include "stddef.h";
struct node
{
	int data;
	struct node *next;
	struct node *pre;
};
struct deque
{
	struct node *front;
	struct node *rear;
};

struct deque s;

int push(int x)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  if(!newnode)
  {
  	printf("out of space\n");
  	return 0;
  }
  newnode->data=x;
  newnode->next=s.front;
  newnode->pre=NULL;
  if(s.front)
  {
  (s.front)->pre=newnode;
  }
  s.front=newnode;
  if(!(s.rear))
  {
  	s.rear=newnode;
  }
  return 1;
}

int pop()
{
	if(!(s.front))
	{
		printf("deque is empty\n");
		return 0;
	}
	struct node *temp=s.front;
	int t=temp->data;
	s.front=temp->next;
	if(temp ==s.rear)
	{
	 s.rear=NULL;
	 free(temp);
	 return t;
	}
	(s.front)->pre=NULL;
	free(temp);
	return t;
}

int inject(int x)
{
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
  if(!newnode)
  {
  	printf("out of space\n");
  	return 0;
  }
  newnode->data=x;
  newnode->next=NULL;
  if(!(s.rear))
  {
  	s.rear=newnode;
  	s.front=newnode;
  	newnode->pre=NULL;
  	return 1;
  }
  (s.rear)->next=newnode;
  newnode->pre=s.rear;
  s.rear=newnode;
  return 1;
}

int eject()
{
	if(!(s.front))
	{
		printf("deque is empty\n");
		return 0;
	}
	struct node *temp=s.rear;
	int t=temp->data;
	s.rear=temp->pre;
	if(temp ==s.front)
	{
		s.front=NULL;
		free(temp);
	     return t;
	}
	(s.rear)->next=NULL;
	free(temp);
	return t;
}

int show()
{
	if(!(s.front))
	{
		printf("empty \n");
		return 0;
	}
	struct node *iter=s.front;
	while(iter)
	{
		printf("%d  ",iter->data);
		iter=iter->next;
	}
return 1;
}

int main()
{
	int a=1,b,c;
	do
	{
	printf("enter the option\n1)push\n2)pop\n3)inject\n4)eject\n5)show\n0)quit\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1 :
		{
			printf("enter the element\n");
			scanf("%d",&c);
			push(c);
			printf("\n");
			break;
		}
		case 2 :
		{
			printf("\n poped:-%d",pop());
			printf("\n");
			break;
		}
		case 3 :
		{
		     printf("enter the element\n");
			scanf("%d",&c);
			inject(c);
			printf("\n");
			break;
		}
		case 4 :
		{
			printf("\nejected:-%d",eject());
			printf("\n");
			break;
		}
		case 5 :
		{
			show();
			printf("\n");
			break;
		}
		default :
		{
			a=0;
		}
	  }
	}
		while(a);
return 0;
}
		