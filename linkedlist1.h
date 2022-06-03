#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int init(struct node **head);
int insert(struct node **head,int data,int pos);
int traversal(struct node *head);
int searchlist(struct node *head,int key,struct node **keyptr);