#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int init(struct node **head);
int insert(struct node **head,int element);
//int delete(struct node **head,int element);
int traversal(struct node *head);