#include<iostream>
#include "stddef.h"
#define capacity 3
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct arrqueue
{
	int front,rear;
	int a[3];
};
struct listqueue
{
	struct node *front;
	struct node *rear;
};
int arr_init(struct arrqueue *);
int arr_enqueue(struct arrqueue *,int );
int arr_dequeue(struct arrqueue *,int *);

int list_init(struct listqueue *);
int list_enqueue(struct listqueue *,int  element);
int list_dequeue(struct listqueue *,int * element);
	