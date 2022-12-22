#include "stack2.h"
int main()
{
	struct stack s;
	init(&s);
	char x[100];
	cout<<"enter the string"<<endl;
	cin.getline(x,100);
	checkpalindrome(&s,x);
	return 0;
}