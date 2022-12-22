#include "arraystack1.h"

int arrinit(struct arrstack *s)
{
	(s->top)=-1;
	return 1;
}

int arrpush(struct arrstack *s,int key)
{
	if(capacity-1==(s->top))
	{
		cout<<"full stack"<<endl;
		return 0;
	}
	s->a[++(s->top)]=key;
	return 1;
}

int arrpop(struct arrstack *s,int *key)
{
	if((s->top)==-1)
	{
		cout<<"empty stack"<<endl;
		return 0;
	}
         *key=s->a[(s->top)--];
         return 1;
}

int arrpeak(struct arrstack *s)
{
	if((s->top)==-1)
	{
		cout<<"empty stack"<<endl;
		return 0;
	}
	cout<<(s->a[(s->top)])<<endl;
	return 1;
}
