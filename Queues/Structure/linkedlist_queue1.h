#include<iostream>
#include "stddef.h"
using namespace std;

struct node
{
	struct node *next;
	int data;
};

struct listqueue
{
	struct node *front;
	struct node *rear;
};


int list_init(struct listqueue *);
int list_enqueue(struct listqueue *,int  element);
int list_dequeue(struct listqueue *,int * element);