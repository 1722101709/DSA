#include "heap2.h"
int main()
{
	struct heap h;
	int a=1,b,c;
	init(&h);
	insert(&h,7);
	insert(&h,3);
	insert(&h,5);
	insert(&h,1);
	insert(&h,9);

	do
	{
	printf("\nenter the option\n1)insertion\n3)search\n4)traversal\n5)get_max\n6)extract_max\n7)increase_key\n8)heapsort\n9)parent of a node\n10)left child of a node\n11)right child of a node\n0)quit\n");
	scanf("%d",&b);
	switch(b)
	{
		case 1 :
		{
			printf("enter the element\n");
			scanf("%d",&c);
			insert(&h,c);
			printf("\n");
			break;
		}
		case 2 :
		{
			printf("enter the element \n");
			scanf("%d",&c);
			deletion(&h,c);
			printf("\n");
			break;
		}
		case 3 :
		{
		     printf("enter the element\n");
			scanf("%d",&c);
			search(&h,c);
			printf("\n");
			break;
		}
		case 4 :
		{
			traversal(&h);
			printf("\n");
			break;
		}
		case 5 :
		{
			printf("%d",get_max(&h));
			printf("\n");
			break;
		}
		case 6 :
		{
			printf("%d",extract_max(&h));
			printf("\n");
			break;
		}
		case 7 :
		{
			printf("give index of the node and increased value\n");
			scanf("%d %d",&a,&c);
			increase_key(&h,a,c);
			break;
		}
		case 8 :
		{
			heapsort(&h);
			break;
		}
		case 9 :
		{
	   	printf("give index of the node\n");
			scanf("%d",&c);
			printf("%d",h.a[parent(c)]);
			break;
		}
	   case 10 :
		{
	   	printf("give index of the node\n");
			scanf("%d",&c);
			printf("%d",h.a[left(c)]);
			break;
		}
		case 11 :
		{
	   	printf("give index of the node\n");
			scanf("%d",&c);
			printf("%d",h.a[right(c)]);
			break;
		}
		default :
		{
			a=0;
		}
	  }
	}
		while(a);
return 0;
}
	