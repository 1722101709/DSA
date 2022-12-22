#include<iostream>
using namespace std;
struct node 
{
	struct node *next;
	int data;
};
int insert(struct node **head,int element)
{
	struct node *newnode=new node;
	newnode->data=element;
	newnode->next=*head;
		*head=newnode;
		return 1;
}
	
int checkprime(int p)
{
  if(p>1)
  {
  for(int i=2;i<p;i++)
  {
  	if(p%i==0)
  	{
  		return 0;
  	}
  }
  	return 1;
  }
  return 0;
}
  int division(int a,int b)
  {
  	while(1)
  	{
  		a=a/b;
  		if(a%b!=0)
  		{
  			return a;
  		}
  	}
  	return 0;
  }
  	
int main()
{
	int x,p;
	struct node *head;
	while(1)
	{
		cout<<"give element in node"<<endl;
		cout<<"or enter -1 to stop giving numbers"<<endl;
		cin>>p;
		if(p==-1)
		{
			break;
		}
		insert(&head,p);
	}
	cout<<"give the number x "<<endl;
	cin>>x;
	struct node *iter=head;
	int a=x;
while(iter)
{
	if(x%(iter->data)==0)
	{
		if(checkprime(iter->data))
		{
			a=division(a,iter->data);
		}
	}
	iter=iter->next;
}
if(a==1)
{
	cout<<"all prime factors of "<<x<<" are \"PRESENT\" in given linkedlist"<<endl;
}
else
{
  cout<<"all prime factors of "<<x<<" are \"NOT PRESENT\" in given linkedlist"<<endl;
}
return 0;
}