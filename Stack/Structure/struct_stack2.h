#include "struct_stack1.h"

int strinit(struct structstack *s)
{
	(s->top)=NULL;
	return 1;
}

int strpush(struct structstack *s,int key)
{
	struct node *newnode=new struct node;
	if(newnode==NULL)
	{
		cout<<"full stack"<<endl;
		return 0;
	}
	newnode->data=key;
	newnode->next=(s->top);
	s->top=newnode;
	return 1;
}

int strpop(struct structstack *s,int *key)
{
	if((s->top)==NULL)
	{
		cout<<"empty stack"<<endl;
		return 0;
	}
	struct node *iter=s->top;
	*key=iter->data;
	  s->top=iter->next;
	  free(iter);
	  return 1;
}

int strpeak(struct structstack *s)
{
	if((s->top)==NULL)
	{
		cout<<"empty stack"<<endl;
		return 0;
	}
	cout<<((s->top)->data)<<endl;
	return 1;
}