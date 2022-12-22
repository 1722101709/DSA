#include "arraystack2.h"
int main()
{
	struct arrstack s1;
	int p;
	arrinit(&s1);

	arrpush(&s1,4);
	arrpush(&s1,3);
	arrpush(&s1,2);
	arrpush(&s1,1);
	
	cout<<"top element in array before poping"<<endl;
	
	arrpeak(&s1);
	
	arrpop(&s1,&p);
	cout<<"top element in array after poping 1st time"<<endl;
	arrpeak(&s1);
	
	arrpop(&s1,&p);
	cout<<"top element in array after poping 2nd time"<<endl;
	arrpeak(&s1);
	return 0;
}