#include"list2.h"
int main()
  {
	struct node *head=NULL;
	struct node *head1=NULL;
	struct node *keyptr=NULL;
	 init(&head);
	 insert(&head,3,1);
	 insert(&head,2,2);
	insert(&head,6,1);
	init(&head1);
	insert(&head1,2,1);
	insert(&head1,3,2);
	insert(&head1,1,1);
	 int a;
	
	 printf("enter the number\n1 for insertion by position\n2 for searching the list\n3 for deletion by element\n4 for deletion by position\n 5 for insertion by element\n");
	 scanf("%d",&a);
	 if(a==1)
	 {
	 	printf("before any operation\n");
	     traversal(head);
	 	printf("enter the number to be inserted and position\n");
	 	int b,c;
	 	scanf("%d",&b);
	 	scanf("%d",&c);
	 	insert(&head,b,c);
	 	printf("after operation\n");
	 	traversal(head);
	 }
	 else if(a==2)
	 {
	 	int d;
	 	int i;
	 	printf("enter 1 for ordered list and 2 for unorderedlist\n");
	 	scanf("%d",&i);
	 	if(i==1)
	 	{
	 	printf("before any operation\n");
	    traversal(head1);
	 	printf("enter the key to be searched");
	 	scanf("%d",&d);
	int p=searchlist(head1,d,&keyptr);
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
	 	if(i==2)
	 	{
	 		printf("before any operation\n");
	         traversal(head);
	     printf("enter the key to be searched");
	 	scanf("%d",&d);
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
	 }
  else if(a==3)
  {
  	int e,f;
  	printf("enter 1 for ordered list and 2 for unorderedlist\n");
	 	scanf("%d",&e);
	 	if(e==1)
	 	{
	 	printf("before any operation\n");
	    traversal(head1);
  printf("enter the element\n");
  	scanf("%d",&f);
  	deletebyelementorderedlist(&head1,f);
  	printf("after operation\n");
  	traversal(head1);
        }
        if(e==2)
        {
        	int z;
	 	printf("before any operation\n");
	     traversal(head);
	     printf("enter the element\n");
  	   scanf("%d",&z);
  	   deletebyelement(&head,z);
  	   printf("after operation\n");
  	   traversal(head);
        }
  }
  else if(a==4)
  {
  	int g;
  	int j;
  	printf("enter 1 for ordered list and 2 for unorderedlist\n");
	 	scanf("%d",&j);
	 	if(j==1)
	 	{
	 	printf("before any operation\n");
	     traversal(head1);
         printf("enter the position\n");
  	   scanf("%d",&g);
  	 deletebyposorderedlist(&head1,g);
  	printf("after operation\n");
  	traversal(head1);
	 	}
	     if(j==2)
	 	{
	 	 printf("before any operation\n");
	      traversal(head);
          printf("enter the position\n");
  	    scanf("%d",&g);
  	deletebypos(&head1,g);
  	printf("after operation\n");
  	traversal(head);
	 	}
  }
  else if(a==5)
  {
  	  int k;
  	  printf("before any operation\n");
	    traversal(head1);
        printf("enter the element\n");
  	  scanf("%d",&k);
  	insertbyelement(&head1,k);
  	printf("after operation\n");
  	traversal(head1);
     }
     else
     {
     	printf("select numbers from 1-5 only\n ");
     }
  return 0;
  }