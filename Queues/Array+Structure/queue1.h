#include<iostream.h>
#include "stddef.h"
#define capacity 50
using namespace std;

struct arrqueue
{
	int a[100];
	int front,rear;
};

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

int arr_init(struct arrqueue *);
int arr_enqueue(struct arrqueue *,int );
int arr_dequeue(struct arrqueue *,int *);

int list_init(struct listqueue *);
int list_enqueue(struct listqueue *,int  element);
int list_dequeue(struct listqueue *,int * element);