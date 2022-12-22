#include "DLL2.h"

int main()
{
	struct node *head=NULL;
	struct node *tail=NULL;
	struct node *ptr=NULL;
	int i,j,k;
	init(&head,&tail);
	insertbypos(&head,&tail,1,5);
    insertbypos(&head,&tail,1,3);
    insertbypos(&head,&tail,2,4);
    insertbypos(&head,&tail,4,6);
    
    fwdtraversal(head);
    bwdtraversal(tail);
    
   printf("--->enter the key to be searched\n");
   scanf("%d",&i);
   search(head,i,&ptr);
    
    
    printf("--->enter the position that is deleted\n");
   scanf("%d",&j);
   deletebypos(&head,&tail,j);
    
    fwdtraversal(head);
    bwdtraversal(tail);
  
    printf("--->enter the element to be deleted\n");
    scanf("%d",&k);
    deleteelement(&head,&tail,k);
    
    fwdtraversal(head);
    bwdtraversal(tail);
    printf("\n");
    
    destroy(&head,&tail);
    
    fwdtraversal(head);
    bwdtraversal(tail);
  return 0;
}