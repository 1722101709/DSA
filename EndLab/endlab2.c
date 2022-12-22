#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
struct node
{
	int data;
	struct node *next;
};

struct structstack
{
	struct node *top;
};

int push(struct structstack *s,int key)
{
	struct node *newnode=new struct node;
	if(newnode==NULL)
	{
		printf("full queue\n");
		return 0;
	}
	newnode->data=key;
	newnode->next=(s->top);
	s->top=newnode;
	return 1;
}

int pop(struct structstack *s,int *key)
{
	if((s->top)==NULL)
	{
		printf("empty queue\n");
		return 0;
	}
	struct node *iter=s->top;
	*key=iter->data;
	  s->top=iter->next;
	  free(iter);
	  return 1;
}

/*int strpeak(struct structstack *s)
{
	if((s->top)==NULL)
	{
		printf("empty queue\n");
		return 0;
	}
	cout<<((s->top)->data)<<endl;
	return 1;
}*/

int dequeue(struct structstack *s1,struct structstack *s2)
{
	int *key=0;
	while(s1->top)
	{
		pop(s1,key);
		push(s2,(*key));
	}
	pop(s2,key);
	printf("%d\n",(*key));
	while(s2->top)
	{
		pop(s2,key);
		push(s1,(*key));
	}
	return 1;
}

int enqueue(struct structstack *s1,int key)
{
	push(s1,key);
	return 1;
}

int main()
{
	struct structstack s1;
	struct structstack s2;
	s1.top=NULL;
	s2.top=NULL;
	int option,a=1,b=0;
	int e[100];
	int c=-1;
	do
	{
		printf("\nchoose the option\n1)enqueue\n2)dequeue\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1 :
			{
				printf("give number\n");
				scanf("%d",&b);
				enqueue(&s1,b);
				c++;
				e[c]=b;
				break;
			}
			case 2 :
			{
				printf("dequeued element:-");
				//dequeue(&s1,&s2);
				if(c<0)
				{
					printf("empty queue\n");
				}
				else
				{
				printf("%d",e[c]);
				c--;
				}
				break;
			}
			default :
			{
			a=0;
			break;
			}
		}
	}
	while(a);
	return 0;
}
			