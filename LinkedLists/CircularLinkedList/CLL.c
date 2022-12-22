#include "CLL2.h"
int main()
{
struct node *tail=NULL;
struct node *ptr=NULL;
int key,i;
init(&tail);
insertbyelement(&tail, -1 ,1);
insertbyelement(&tail, 1, 2);
insertbyelement(&tail, 2, 3);
insertbyelement(&tail, 3, 4);

traverse(tail);
printf("give the key\n");
scanf("%d",&key);

search(tail, key, &ptr);

printf("give the number to be deleted\n");
scanf("%d",&i);

deleteelement(&tail, i);

traverse(tail);
return 0;
}