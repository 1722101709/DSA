#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
#define max 10
struct node 
{
	int data;
	struct node *next;
};
struct hash
{
	struct node *front[max];
};

struct hash s;

int insert(int x)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(!newnode)
	{
		printf("out of memory\n");
		return 0;
	}
	int a=x%10;//hash function;
	newnode->next=s.front[a];
	s.front[a]=newnode;
	newnode->data=x;
	return 1;
}

int deletion(int x)
{
  	int a=x%10;
  	struct node *iter=s.front[a];
  	if(!iter)
  	{
  		printf("hash table is empty\n");
  		return 0;
  	}
  	if(iter->data==x)
  	  {
  	  	s.front[a]=NULL;
  	  	free(iter);
  	  	return 1;
  	  }
  	while(iter->next)
  	{
  		if((iter->next)->data ==x)
  		{
  			struct node *temp=iter->next;
  			iter->next=temp->next;
  			free(temp);
  			return 1;
  			}
  			iter=iter->next;
  	  }
  	  printf("element not found\n");
  	  return 0;
}

int search(int x)
{
  	int a=x%10;
  	struct node *iter=s.front[a];
  	if(!iter)
  	{
  		printf("element not found\n");
  		return 0;
  	}
  	while(iter)
  	{
  		if(iter->data ==x)
  		{
  			printf("element found\n");
  			return 1;
  		}
  		iter=iter->next;
  	}
  	printf("element not found\n");
  	return 0;
}
  
 int showtable()
{
  	for(int a=0;a<10;a++)
  	{
  	struct node *iter=s.front[a];
  	printf("%d =",a);
  	if(iter)
  	{
  	while(iter)
  	{
  			printf("%d->",iter->data);
           iter=iter->next;
  	}
  	}
     printf("\n");
  	}
  	return 1;
}	

int main()
{
	for(int a=0;a<10;a++)
	{
		s.front[a]=NULL;
	}
	int a=1,b,c;
	do
	{
	printf("enter the option\n1)insertion\n2)deletion\n3)search\n4)show_hash_table\n0)quit\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1 :
		{
			printf("enter the element\n");
			scanf("%d",&c);
			insert(c);
			printf("\n");
			break;
		}
		case 2 :
		{
			printf("enter the element\n");
			scanf("%d",&c);
			deletion(c);
			printf("\n");
			break;
		}
		case 3 :
		{
		     printf("enter the element\n");
			scanf("%d",&c);
			search(c);
			printf("\n");
			break;
		}
		case 4 :
		{
			showtable();
			printf("\n");
			break;
		}
		default :
		{
			a=0;
		}
	  }
	}
		while(a);
return 0;
}