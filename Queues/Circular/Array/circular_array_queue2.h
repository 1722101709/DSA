#include "circular_array_queue1.h"
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