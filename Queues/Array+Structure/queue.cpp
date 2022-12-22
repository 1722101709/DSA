#include "queue2.h"
int main()
{
struct arrqueue q1;
struct listqueue q2;
int element;
arr_init(&q1);
list_init(&q2);
cout<<"------------>array queues<--------------"<<endl<<endl;
arr_enqueue(&q1,1);
arr_enqueue(&q1,2);
arr_enqueue(&q1,3);

arr_dequeue(&q1,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q1,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q1,&element);
cout<<"dequeued element="<<element<<endl;

arr_dequeue(&q1,&element);


cout<<"------------->linked_list queues<--------"<<endl<<endl;
list_enqueue(&q2,1);
list_enqueue(&q2,2);
list_enqueue(&q2,3);

list_dequeue(&q2,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q2,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q2,&element);
cout<<"dequeued element="<<element<<endl;

list_dequeue(&q2,&element);

return 0;
}