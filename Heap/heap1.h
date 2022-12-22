#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "stddef.h"
#define capacity 50

struct heap
{
	int a[capacity];
	int heapsize;
};
int init(struct heap *h);
int insert(struct heap *h,int element);
int traversal(struct heap *h);
int heapify(struct heap *h,int i);
int parent(int i);
int left(int i);
int right(int i);
int get_max(struct heap *h);
int extract_max(struct heap *h);
int increase_key(struct heap *h,int i,int element);
int deletion(struct heap *h,int key);
int search(struct heap *h,int key);
int heapsort(struct heap *h);
