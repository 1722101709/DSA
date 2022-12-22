#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct queuenode
{
	int data;
	struct queuenode *next;
};
struct queue
{
	struct queuenode *front;
	struct queuenode *rear;
};

int insert(struct node **root,int element);
int search(struct node *root,int key,struct node **keyptr);
int preorder_traversal(struct node *root);
int postorder_traversal(struct node *root);
int inorder_traversal(struct node *root);
int deletion(struct node **root,int element);
int breadthfirst_traversal(struct node *root);
int enqueue(struct queue *q,int element);
int dequeue(struct queue *q,int *ptr);
