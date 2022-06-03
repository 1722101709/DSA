#include"unorderedlist2.h"
int main()
  {
	struct node *head=NULL;
	struct node *keyptr=NULL;
	 init(&head);
	 int a;
	 printf("before any operation\n");
	 insert(&head,3,1);
	 insert(&head,2,2);
	insert(&head,6,1);
	traversal(head);
	 printf("enter the number\n1 for insertion by position\n2 for searching the list\n3 for deletion by element\n4 for deletion by position");
	 scanf("%d",a);
	 if(a==1)
	 {
	 	printf("enter the number to be inserted and position\n");
	 	int b,c;
	 	scanf("%d",b);
	 	scanf("%d",c);
	 	insert(&head,b,c);
	 	tranverse(&head);
	 }
	 if(a==2)
	 {
	 	int d;
	 	printf("enter the key to be searched");
	 	scanf("%d",d);
	int p=searchlist(head,d,&keyptr);
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
  }
  if(a==3)
  {
  	int e,f;
  printf("enter the element and position");
  	scanf("%d ",e);
  	scanf("%d",f);
  	deletebypos(&head,e,f);
  	traverse(head);
  }
  if(a==4)
  {
  	int g;
  printf("enter the number to be deleted");
  scanf("%d",g);
  deletebyelement(&head,g);
  traverse(head);
  }
  return 0;
  }