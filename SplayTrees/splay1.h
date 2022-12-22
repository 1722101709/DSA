#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

int insert(struct node **,int );
int deletion(struct node **,int );
int search(struct node **,int );
int inorder_traversal(struct node *);
int preorder_traversal(struct node *);
int postorder_traversal(struct node *);
int zig(struct node **,int );
int zig_zig(struct node **,int );
int zig_zag(struct node **,int );
