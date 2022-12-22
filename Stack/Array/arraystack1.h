#include<iostream.h>
#include "stddef.h"
#define capacity 50
using namespace std;

struct arrstack
{
	int a[100];
	int top;
};
int arrinit(struct arrstack *);
int arrpush(struct arrstack *,int );
int arrpop(struct arrstack *,int *);
int arrpeak(struct arrstack *);