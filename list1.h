#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int init(struct node **head);
int insertbypos(struct node **head,int element,int pos);
int tranversal(struct node *head);
int searchlist(struct node *head,int element,struct node **keyptr);
int deletebypos(struct node **head,int pos);
int deletebyelement(struct node **head,int element);
int insertbyelement(struct node **head,int element);
int searchorderedlist(struct node *head,int element,struct node **ptr);
int deletebyelementorderedlist(struct node **head,int element);
int deletebyposorderedlist(struct node **head,int position);