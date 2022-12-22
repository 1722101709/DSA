#include<stdio.h>
#include<stdlib.h>
#include "stddef.h"
#define capacity 5
struct element
{
	int data;
	struct set *setptr;
	struct element *next;
};
struct set
{
	struct element *nextptr;
	int setid;
};
struct arrayset
{
	struct set * sets[capacity];
};

int makeset(struct arrayset *s);
int findset(struct arrayset *s,int element);
int union_sets(struct set **s1,struct set **s2);
int show_sets(struct arrayset *s);
