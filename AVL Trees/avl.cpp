#include "avl2.h"

int main()
{
	struct node *root=NULL;
	int a,b,c=1;
    insert(&root,5);
	insert(&root,3);
	insert(&root,7);
	insert(&root,9);

	do
	{
	cout<<"choose the option"<<endl<<"1)insertion\n2)preorder_traversal\n3)inorder_traversal\n4)postorder_traversal\n5)deletion\n0)quit"<<endl;
	cin>>a;
	switch(a)
	{
		case 1 :
		{
			cout<<"give the element to be inserted"<<endl;
			 cin>>b;
			insert(&root,b);
			cout<<endl;
			break;
		}
		case 2 :
		{
      	preorder_traversal(root); 
      	cout<<endl;
      	break;
		}
		case 3 :
		{
		   inorder_traversal(root); 
		   cout<<endl;
		   break;
		}
		case 4 :
		{
		 	postorder_traversal(root); 
		 	cout<<endl;
		 	break;
		}
		default :
		{
		    	c=0;
		}
  	}
	}
	while(c);
      	return 0;
}