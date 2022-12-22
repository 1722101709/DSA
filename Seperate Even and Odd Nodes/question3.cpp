#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
int insert(struct node **head,int element)
{
struct node *newnode=new node;
newnode->data=element;
newnode->next=*head;
*head=newnode;
return 1;
}
int traverse(struct node *head)
{
	struct node *iter=head;
	while(iter)
	{
		cout<<(iter->data)<<"->";
		iter=iter->next;
	}
	return 0;
}
int back(struct node *head,struct node **temp)
{
	struct node *iter=head;
	while((iter->next)!=*temp)
	{
		iter=iter->next;
	}
	*temp=iter;
	return 1;
}
		
int pick(struct node *iter,struct node **temp)
{
	while(iter!=*temp)
	{
		back(iter,temp);
		if((*temp)->data%2==1)
		{
			return 1;
		}
	}
	return 0;
}
int seperation(struct node **head,struct node **evenhead,struct node **oddhead)
{
	 
	struct node *temp;
	struct node *iter=*head;
	while(iter)
	{
		
		if((iter->data)%2==0)
		{
			if(pick(iter,&temp))
			{
			int a=iter->data;
			iter->data=temp->data;
			temp->data=a;
			}
			else
		    {
		    	break;
		    }
		}
		iter=iter->next;
	}
	*evenhead=temp->next;
	temp->next=NULL;
	*oddhead=*head;
	return 1;
}
int main()
{
struct node *head;
struct node *evenhead;
struct node *oddhead;
for(int i=10;i>0;i--)
{
	insert(&head,i);
}
traverse(head);
cout<<endl;
seperation(&head,&evenhead,&oddhead);
traverse(head);
return 0;
}