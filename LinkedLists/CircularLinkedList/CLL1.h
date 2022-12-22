#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
struct node
{
	int data;
	struct node *next;
};
int init(struct node **);
int insertbyelement(struct node **,int ,int );
int search(struct node *,int ,struct node ** );
int traverse(struct node *);
int deleteelement(struct node **,int);