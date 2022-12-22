#include "struct_stack2.h"
int main()
{
	struct structstack s2;
	int p;
	
	strpush(&s2,3);
	strpush(&s2,2);
	strpush(&s2,1);
	
    cout<<"top element in linked list before   poping"<<endl;
	strpeak(&s2);
	
	strpop(&s2,&p);
	cout<<"top element in linked list after   poping 1st time"<<endl;
	strpeak(&s2);
	
	strpop(&s2,&p);
	cout<<"top element in linked list after poping 2times"<<endl;
	strpeak(&s2);
	return 0;
}