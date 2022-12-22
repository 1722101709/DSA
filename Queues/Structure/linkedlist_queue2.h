#include "linkedlist_queue1.h"

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