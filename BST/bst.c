#include "bst2.h"

int main()
{
	struct node *root=NULL;
	int option,a;
	struct node *keyptr;
	 insert(&root,5);
     insert(&root,2);
	 insert(&root,3);
	 insert(&root,6);
	 insert(&root,7);
	  
	do
	{
  printf("no-----> operation\n1)insertion\n2)deletion\n3)searching\n4)inorder traversal\n5)preorder traversal\n6)postorder traversal\n7)finding minimum\n8)finding maximum\n9)breadthfirst traversal\n0)quit\n");
  scanf("%d",&option);
  switch(option)
  {
  	case 0 : break;
  	case 1 :
  	{
  		 printf("give the element\n");
  		 scanf("%d",&a);
  		 printf("\n");
  		 insert(&root,a);
  		 break;
  	}
  	case 2 :
  	{
  		printf("give the element\n");
  		 scanf("%d",&a);
  		 printf("\n");
  		 deletion(&root,a);
  		 break;
  	}
  	case 3 :
  	{
  		printf("give the element\n");
  		 scanf("%d",&a);
  		 printf("\n");
  		if(search(root,a,&keyptr))
  		 {
  		 	printf("\"key found\"\n");
  		 }
  		 break;
  	}
  	case 4 :
  	{
  		 printf("\n");
  		 inorder_traversal(root);
           break;
  	}
  	case 5 :
  	{
  		 printf("\n");
  		 preorder_traversal(root);
           break;
  	}
  	case 6 :
  	{
  		 printf("\n");
  		 postorder_traversal(root);
           break;
  	}
  	case 7 :
  	{
  		findmin(root,&a);
  		printf("\n");
  		printf("minimum element=\"%d\"\n",a);
  		break;
  	}
  	case 8 :
  	{
  		findmax(root,&a);
  		printf("\n");
  		printf("maximum element=\"%d\"\n",a);
  		break;
  	}
  	case 9 :
  	{
  		printf("\n");
  		breadthfirst_traversal(root);
  	}
  }
  printf("\n\n");
	}
	while(option);
  return 0;
}