#include<string.h>
#include "stack1.h"
int init(struct stack *s)
{
	s->top=NULL;
}
int checkpalindrome(struct stack *s,char a[])
{
	int len=strlen(a);
     for(int i=0;i<len;i++)
	{
		push(s,a[i]);
	}
	for(int j=0;j<(len-1)/2;j++)
	{
		char *p;
		 pop(s, p);
		if(*p!=a[j])
		{
			cout<<"not palindrome\n";
			return 0;
	    }
	}
	cout<<"palindrome\n";
	return 1;
}
int push(struct stack *s,char key)
{
 struct node *newnode=new struct node;
	if(newnode==NULL)
	{
		cout<<"full stack\n";
		return 0;
	}
	newnode->data=key;
	newnode->next=s->top;
	s->top=newnode;
	return 1;
}
int pop(struct stack *s,char *element)
{
	if(s->top==NULL)
	{
		return 1;
	}
	struct node *temp=s->top;
	*element=temp->data;
	s->top=s->top->next;
	free(temp);
	return 1;
}