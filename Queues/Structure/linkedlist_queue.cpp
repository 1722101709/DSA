#include "linkedlist_queue2.h"
int main()
{
struct listqueue q;
int element;

list_init(&q);

cout<<"------------->linked_list queues<--------"<<endl<<endl;
list_enqueue(&q,1);
list_enqueue(&q,2);
list_enqueue(&q,3);

list_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q,&element);

return 0;
}