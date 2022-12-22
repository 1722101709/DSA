#include<iostream.h>
#include "stddef.h"
#define capacity 50
using namespace std;

struct arrqueue
{
	int a[100];
	int front,rear;
};

int arr_init(struct arrqueue *);
int arr_enqueue(struct arrqueue *,int );
int arr_dequeue(struct arrqueue *,int *);
