#define _CRT_SECURE_NO_WARNINGS
#include "QueueBase.h"
#include "ArrayQueue.h"
#include "LinkQueue.h"
#include <iostream>
using namespace std;

void testQueue(QueueBase* q)
{
    q->Enqueue(10);
    q->Enqueue(20);
    q->Enqueue(30);

    cout << "队头：" << q->Front() << endl;
    cout << "出队：" << q->FrontAndDequeue() << endl;
    cout << "是否空：" << boolalpha << q->IsEmpty() << endl;
    q->MakeEmpty();
}

int main()
{
    // 多态切换，只用改一行
    QueueBase* q1 = new ArrayQueue(10);  // 数组队列
    // QueueBase* q1 = new LinkQueue();   // 链表队列

    testQueue(q1);
    delete q1;
    return 0;
}
