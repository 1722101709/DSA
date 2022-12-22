#include<iostream.h>
#include "stddef.h"
using namespace std;
struct node
{
	struct node *next;
	int data;
};
struct structstack
{
	struct node *top;
};

int strinit(struct structstack *);
int strpush(struct structstack *,int );
int strpop(struct structstack *,int *);
int strpeak(struct structstack * );