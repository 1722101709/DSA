#include "arrayqueue1.h"
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