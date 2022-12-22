#include "disjoint_sets1.h"

int makeset(struct arrayset *s)
{
	for(int i=0;i<capacity;i++)
	{
		struct set *newset=(struct set *)malloc(sizeof(struct set));
	     s->sets[i]=newset;
	     newset->nextptr=NULL;
	     newset->setid=i+1;
	}
	
   for(int i=1;i<=10;i++)
    {
       struct element *newnode=(struct element *)malloc(sizeof(struct element));
     if(i<6)
       {
       	(s->sets[i-1])->nextptr=newnode;
       	newnode->setptr=s->sets[i-1];
       }
       else
       {	
   ((s->sets[i-6])->nextptr)->next=newnode;
       	newnode->setptr=s->sets[i-6];
       }
       newnode->data=i;
       newnode->next=NULL;
    }
return 0;
}

int findset(struct arrayset *s,int element)
{
	for(int i=0;i<capacity;i++)
	{
		if(s->sets[i])
		{
		struct element *iter=(s->sets[i])->nextptr;
		while(iter)
		{
	  	if(iter->data ==element)
  		{
			return i;
  		}
			iter=iter->next;
		}
     } 
   }
}
int union_sets(struct set **s1,struct set **s2)
{
	struct element *iter=(*s1)->nextptr;
	while((iter->next))
	{
		iter=iter->next;
	}
	iter->next=(*s2)->nextptr;
	free(*s2);
	while(!iter)
	{
		iter->setptr=*s1;
	}
	return 1;
}

int show_sets(struct arrayset *s)
{
	for(int i=0;i<capacity;i++)
	{
		if(s->sets[i])
		{
		struct element *iter=(s->sets[i])->nextptr;
		printf("set %d:-",i);
		while(iter)
		{
			printf(" %d",iter->data);
			iter=iter->next;
		}
		printf("\n");
  	}
  	else
  	{
  		printf("set %d:-empty\n",i);
   	}
	}
	return 1;
}