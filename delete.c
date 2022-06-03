#include"delete2.h"
int main()
{
	struct node *head=NULL;
	init(&head);
	insert(&head,7);
	insert(&head,3);
	insert(&head,9);
	traversal(head);
	return 0;
}