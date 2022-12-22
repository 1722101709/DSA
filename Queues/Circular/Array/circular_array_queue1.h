#include<iostream>
#include "stddef.h"
#define capacity 3
using namespace std;

struct arrqueue
{
	int front,rear;
	int a[3];
};

int arr_init(struct arrqueue *);
int arr_enqueue(struct arrqueue *,int );
int arr_dequeue(struct arrqueue *,int *);
