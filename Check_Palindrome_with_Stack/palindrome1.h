#include<iostream.h>
#include "stddef.h"
using namespace std;

struct node
{
	struct node *next;
	char data;
};
struct stack
{
	struct node *top;
};
int init(struct stack *);
int checkpalindrome(struct stack *,char []);
int push(struct stack *,char );
int pop(struct stack *,char *);