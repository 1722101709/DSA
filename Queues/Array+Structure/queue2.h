#include "queue1.h"
int arr_init(struct arrqueue *q)
{
	q->rear=q->front=-1;
	return 1;
}
int arr_enqueue(struct arrqueue *q,int element)
{
	if(q->rear==capacity-1)
	{
		cout<<"full queue"<<endl;
		return 0;
	}
	q->a[++(q->rear)]=element;
	if(q->rear==0)
	{
		(q->front)++;
	}
	return 1;
}
int arr_dequeue(struct arrqueue *q,int *element)
{
	if(q->front==-1)
	{
		cout<<"empty queue"<<endl;
		return 1;
	}
	*element=q->a[(q->front)++];
	if(q->front>q->rear)
	{
		q->front=q->rear=-1;
	}
	return 1;
}
int list_init(struct listqueue *q)
{
	q->front=q->rear=NULL;
	return 1;
}
int list_enqueue(struct listqueue *q,int element)
{
	struct node *newnode=new struct node;
	if(!(newnode))
	{
		cout<<"out of memory"<<endl;
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
int list_dequeue(struct listqueue * q,int *element)
{
	if(!q->front)
	{
		cout<<"empty queue"<<endl;
		return 1;
	}
	*element=(q->front)->data;
	struct node *temp=q->front;
	q->front=(q->front)->next;
	if(!q->front)
	{
		q->rear=NULL;
	}
	free(temp);
	return 1;
}