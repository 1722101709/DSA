#include "arrayqueue2.h"
int main()
{
struct arrqueue q;
int element;
arr_init(&q);

cout<<"------------>array queues<--------------"<<endl<<endl;

arr_enqueue(&q,1);
arr_enqueue(&q,2);
arr_enqueue(&q,3);

arr_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q,&element);

return 0;
}