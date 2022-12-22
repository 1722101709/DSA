#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

int insert(struct node **root,int element)
{
	if(!(*root))
	{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));

newnode->data=element;
		*root=newnode;
		newnode->left=NULL;
		newnode->right=NULL;
		return 1;
	}
	else if(((*root)->data)>element)
	{
	  return insert(&((*root)->left),element);       }
	else if(((*root)->data)<element)
	{
	 return insert(&((*root)->right),element);
	}
	else
	{
	   printf("duplicates not allowed\n");
	   return 0;
	}
}

int inorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	inorder_traversal(root->left);
	printf("%d    ",root->data);
	inorder_traversal(root->right);
	return 1;
}

int preorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	printf("%d    ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	return 0;
}

int postorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	printf("%d    ",root->data);
	return 1;
}

int search(struct node *root,int key,struct node **keyptr)
{
	static int a=0;
	if(!(root))
	{
		if(a)
		{
			printf("element not found\n");
		}
		else
		{
			printf("nothing element in the tree\n");
		}
		return 0;
	}
		
	else if((root->data) > key)
	{
	   	a++;
	return search(root->left,key,keyptr);     
     }
    else if((root->data) < key)
	{
	  	a++;
	  return search(root->right,key,keyptr);
	}
	else
	{
			a++;
		*keyptr=root;
		return 1;
	}
}

int findmin(struct node *root,int *minptr)
{
	if(root)
	{
	if(!(root->left))
	{
		*minptr=root->data;
		return 1;
	}
	findmin(root->left,minptr);
	return 1;
	}
	return 0;
}

int findmax(struct node *root,int *maxptr)
{
	if(root)
	{
	if(!(root->right))
	{
		*maxptr=root->data;
		return 1;
	}
	findmax(root->right,maxptr);
	return 1;
	}
	return 0;
}
	

int deletion(struct node **root,int element)
{
	static int a=0;
	if(!(*root))
	{
		if(a)
		{
			printf("element to be deleted hasn't found\n");
		}
		else
		{
			printf("no element is there in the tree");
		}
		return 0;
	}
	
	else if(((*root)->data) > element)
	{
	  return deletion(&((*root)->left),element);     
     }
    else if(((*root)->data) < element)
	{
	  return deletion(&((*root)->right),element);
	}
	else
	{
		if(!((*root)->left))
		{
			struct node *temp=*root;
			*root=(*root)->right;
			free(temp);
			return 1;
		}
		else if(!((*root)->right))
		{
			struct node *temp=*root;
			*root=(*root)->left;
			free(temp);
			return 1;
		}
		else
		{
			int min=0;
			findmin((*root)->right,&min);
			(*root)->data=min;
			deletion(&((*root)->right),min);
			return 1;
		}
	}
	a++;
}

int findpre(struct node *root,int key,struct node **preptr)
{
   
   int *predvalue=0;
   if(search(root,key,preptr))
   {
   if((*preptr)->left)
   {
   findmax((*preptr)->left,predvalue);
   printf("%d",*predvalue);
   return 1;
   }
   else
   {
   	printf("no predeccessor\n");
   	return 0;
    }
   }
   return 0;
}
int findsucc(struct node *root,int key,struct node **succptr)
{

   int *succvalue=0;
   if(search(root,key,succptr))
   {
   if((*succptr)->right)
   {
   findmin((*succptr)->right,succvalue);
   printf("%d",*succvalue);
   return 1;
   }
   else
   {
   	printf("no successor \n");
   	return 0;
    }
   }
   return 0;
}

int main()
{
	struct node *root=NULL;
	struct node *temp=NULL;
	int option,a;
	struct node *keyptr;
	 insert(&root,5);
     insert(&root,2);
	 insert(&root,3);
	 insert(&root,6);
	 insert(&root,7);
	  
	do
	{
  printf("no-----> operation\n1)insertion\n2)deletion\n3)searching\n4)inorder traversal\n5)preorder traversal\n6)postorder traversal\n7)finding minimum\n8)finding maximum\n9)find predecessor\n10)find successor\n0)quit\n");
  scanf("%d",&option);
  switch(option)
  {
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
  		printf("\ngive the node key\n");
  		scanf("%d",&a);
  		findpre(root,a,&temp);
  		break;
  	}
  	case 10 :
  	{
  		printf("\ngive the node key\n");
  		scanf("%d",&a);
  		findsucc(root,a,&temp);
  		break;
      }
      default :
      {
      	option=0;
      	break;
      }
  }
  printf("\n\n");
	}
	while(option);
  return 0;
}