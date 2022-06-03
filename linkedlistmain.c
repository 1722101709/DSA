#include"linkedlist2.h"
int main()
{
	struct node *head=NULL;
	struct node *keyptr=NULL;
	 init(&head);
	 insert(&head,3,1);
	 insert(&head,2,2);
	insert(&head,6,1);
	traversal(head);
	int p=searchlist(head,3,&keyptr);
	if(p==1)
	{
	 printf("key found");
	}
    else if(p==-1)
    {
    printf("empty list");
    }
	else
	{
		printf("key not found");
	}
	return 0;
}