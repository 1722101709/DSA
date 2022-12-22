#include "heap1.h"

int init(struct heap *h)
{
	for(int i=0;i<capacity;i++)
	{
		h->a[i]=0;
	}
	return 1;
}

int parent(int i)
{
	return floor(i/2);
}

int left(int i)
{
	return (2*i);
}

int right(int i)
{
	return (2*i+1);
}

int heapify(struct heap *h,int i)
{
  if(i<=((h->heapsize)/2))
  {
	int l=left(i);
	int r=right(i);
	int max;
	
	   max=((h->a[i])>(h->a[l]))?i:l;
	   if(r <= h->heapsize)
	   {
	   max=((h->a[r])>(h->a[max]))?r:max;
	   }
	if(max==r)
	{
		int temp=h->a[r];
		h->a[r]=h->a[i];
		h->a[i]=temp;
		return heapify(h,r);
	}
	 else if(max==l)
	  {
		int temp=h->a[l];
		h->a[l]=h->a[i];
		h->a[i]=temp;
		return heapify(h,l);
	}
	else
	{
		return 1;
	 }
   }
	else
	{
		return 0;
	}
}

int insert(struct heap *h,int element)
{
	if(h->heapsize < capacity)
	{
	h->a[++(h->heapsize)]=element;
	int n=(floor((h->heapsize)/2));
	for(int j=n;j>0;j--)
	{
	    heapify(h,j);
	}
  }
  return 1;
}
int traversal(struct heap *h)
{
	for(int i=1;i<=(h->heapsize);i++)
	{
	    printf("%d ",h->a[i]);
	}
	return 1;
}

int get_max(struct heap *h)
{
	return h->a[1];
}

int extract_max(struct heap *h)
{
	int temp=h->a[1];
	h->a[1]=h->a[(h->heapsize)];
	h->a[(h->heapsize)]=temp;
	(h->heapsize)--;
 	heapify(h,1);
	return temp;
}

int increase_key(struct heap *h,int i,int element)   
{
	if((i > (h->heapsize)) || (h->a[i] > element))
	{
		printf("element at slot no %d is already greater than the given element or invalid index\n",i);
	return 0;
	}
  h->a[i]=element;
  while(i!=1)
  {
  	if((h->a[i]) > (h->a[parent(i)]))
  	{
  	int temp=h->a[i];
  	h->a[i]=h->a[parent(i)];
  	h->a[parent(i)]=temp;
  	}
  	i=parent(i);
  }
return 1;
}

int search(struct heap *h,int key)
{
	for(int i=1;(i<=h->heapsize);i++)
	{
		if(h->a[i]==key)
		{
			return i;
		}
	}
	return 0;
}

int deletion(struct heap *h,int key)
{
	int k=search(h,key);
	if(k)
	{
		h->a[k]=-1;
		heapify(h,k);
		(h->heapsize)--;
		
		return 1;
	}
	printf("element not found\n");
	return 0;
}

int heapsort(struct heap *h)
{
	int k=h->heapsize;
	for(int i=1;i<=k;i++)
	{
		int m=extract_max(h);
        h->a[(h->heapsize)+1]=m;
	}
	h->heapsize=k;
	traversal(h);
	for(int j=((h->heapsize)/2);j>0;j--)
	{
	    heapify(h,j);
	}
	return 1;
}

	