#include<iostream>
#include "stddef.h"
using namespace std;

struct node
{
	struct node *left;
	struct node *right;
	int data;
};

int insert(struct node *,int );
int deletion(struct node *,int );
int inorder_traversal(struct node );
int preorder_traversal(struct node );
int postorder_traversal(struct node );
int restore_left_balance(struct node **);
int restore_right_balance(struct node **);
int balancefactor(struct node *root);
int rotate_left(struct node **);
int rotate_right(struct node **);
int height(struct node *);