#include "avl1.h"

int insert(struct node **root,int element)
{
    if(!(*root))
    {
    	struct node *newnode=new node;
    	newnode->data=element;
    	newnode->right=NULL;
    	newnode->left=NULL;
    	*root=newnode;
    	return 1;
    }
    else if((*root)->data > element)
    {
    	insert(&((*root)->left),element);
    	if(balancefactor(*root) > 1)
    	{
    		restore_left_balance(root);
    	}
    	   return 1;
    }
    else if((*root)->data < element)
    {
    	 insert(&((*root)->right),element);
    	 if(balancefactor(*root) < -1)
    	 {
    	 	restore_right_balance(root);
    	 }
    	    return 1;
    }
    else
    {
       cout<<"duplicates are not allowed "<<endl;
    	 return 0;
    }
}

int restore_left_balance(struct node **root)
{
    if(balancefactor(((*root)->left)) < 0)
      {
      	rotate_left(&((*root)->left));
      }
      rotate_right(root);
      return 1;
}
      	
int restore_right_balance(struct node **root)
{
    if(balancefactor(((*root)->right)) > 0)
      {
      	rotate_right(&((*root)->right));
      }
      rotate_left(root);
      return 1;
}

int rotate_right(struct node **root)
{
	struct node *temp=(*root)->left;
	(*root)->left=((*root)->left)->right;
	temp->right=*root;
	*root=temp;
	return 1;
}

int rotate_left(struct node **root)
{
	struct node *temp=(*root)->right;
	(*root)->right=((*root)->right)->left;
	temp->left=*root;
	*root=temp;
	return 1;
}

int balancefactor(struct node *root)
{
  int count=height(root->left)-height(root->right);
	return count;
}

int height(struct node *temp)
{
	 int left,right,count;
     if(temp)
	{
		left=height(temp->left);
		right=height(temp->right);
	
	count=(left>right)? left:right;
	return count+1;
	}
	return 0;
}

int inorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	inorder_traversal(root->left);
	cout<<root->data<<" ";
	inorder_traversal(root->right);
	return 1;
}

int preorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
     cout<<root->data<<" ";
	preorder_traversal(root->left);
	preorder_traversal(root->right);
	return 1;
}

int postorder_traversal(struct node *root)
{
	if(!(root))
	{
		return 0;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout<<root->data<<" ";
	return 1;
}

