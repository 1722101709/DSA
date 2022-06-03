#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
int init(struct node **,struct node **);
int insertbypos(struct node **,struct node  **,int ,int );
int insertbyelement(struct node **,struct node  **,int );
int fwdtraversal(struct node *);
int bwdtraversal(struct node *);
int search(struct node *,int ,struct node **);
int deleteelement(struct node **,struct node **,int );
int deletebypos(struct node **,struct node **,int );
int destroy(struct node **,struct node **);