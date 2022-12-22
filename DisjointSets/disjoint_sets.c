#include "disjoint_sets2.h"
int main()
{
	struct arrayset s;
	int i,b,a,c=1;
	makeset(&s);
	do
	{
	printf("\ntake one of following option\n1)findset\n2)union of two sets\n3)show the disjoint_sets\n0)quit\n");
	scanf("%d",&a);
	printf("\n");
	switch(a)
	{
		case 1 :
		{
			printf("give the element\n");
			scanf("%d",&b);
	printf("set no:-%d\n",findset(&s,b));
	break;
		}
		case 2 :
		{
		  printf("give the two set numbers\n---->note:-second set merges into the first.so \"there will be no more second set after union operation\"\n");
		  scanf("%d %d",&b,&i);
	union_sets(&(s.sets[b]),&(s.sets[i]));
	s.sets[i]=NULL;
	break;
		}
		case 3 :
		{
	show_sets(&s);
	break;
		}
		case 0 :
		{
			c=0;
			break;
		}
		default :
		{
			printf("select only 0,1,2,3\n");
			break;
		}
	  }
	}
	while(a);
return 0;	
}