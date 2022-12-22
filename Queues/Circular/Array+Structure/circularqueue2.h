#include "circularqueue1.h"
int arr_init(struct arrqueue *q)
{
	q->front=q->rear=-1;
	return 1;
}

int arr_enqueue(struct arrqueue *q,int element)
{
	if((q->front)!=((q->rear)+1)%capacity)
	{
		if(q->front==-1)
		{
			(q->front)++;
		}
	q->rear=((q->rear)+1)%capacity;
	q->a[q->rear]=element;
	return 1;
	}
	cout<<"full queue"<<endl;
	return 0;
}
int arr_dequeue(struct arrqueue *q,int *element)
{
	if(q->front==-1)
	{
		cout<<"empty queue"<<endl;
		return 1;
	}
	*element=q->a[q->front];
	if(q->front==q->rear)
	{
		q->front=q->rear=-1;
		return 1;
	}
	q->front=((q->front)+1)%capacity;
	return 1;
}

int list_init(struct listqueue *q)
{
	q->front=q->rear=NULL;
	return 1;
}

int list_enqueue(struct listqueue *q,int element)
{
	struct node *newnode=new node;
	if(!(newnode))
	{
		cout<<"out of memory"<<endl;
	return 0;
	}
	newnode->data=element;
	if(!(q->front))
	{
		q->front=newnode;
		q->rear=newnode;
		return 1;
	}
	(q->rear)->next=newnode;
	newnode->next=q->front;
	q->rear=newnode;
	return 1;
}

int list_dequeue(struct listqueue *q,int *element)
{
	if(!(q->front))
	{
		cout<<"empty queue"<<endl;
		return 0;
	}
	struct node *temp=q->front;
	*element=(q->front)->data;
	if(q->front==q->rear)
	{
		q->front=q->rear=NULL;
		free(temp);
		return 1;
	}
	(q->rear)->next=(q->front)->next;
	q->front=(q->front)->next;
	free(temp);
	return 1;
}