#define _CRT_SECURE_NO_WARNINGS
#include "LinkQueue.h"
#include <cassert>

LinkQueue::LinkQueue()
{
    front = rear = nullptr;
}

LinkQueue::~LinkQueue()
{
    MakeEmpty();
}

bool LinkQueue::IsEmpty() const
{
    return front == nullptr;
}

bool LinkQueue::IsFull() const
{
    return false; // Á´±íÓÀÔ¶²»Âú
}

void LinkQueue::MakeEmpty()
{
    QueueNode* p;
    while (front)
    {
        p = front;
        front = front->next;
        delete p;
    }
    rear = nullptr;
}

void LinkQueue::Enqueue(ElementType x)
{
    QueueNode* newNode = new QueueNode(x);
    if (IsEmpty())
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

ElementType LinkQueue::Front() const
{
    assert(!IsEmpty());
    return front->data;
}

void LinkQueue::Dequeue()
{
    assert(!IsEmpty());
    QueueNode* tmp = front;
    front = front->next;
    delete tmp;
    if (!front) rear = nullptr;
}

ElementType LinkQueue::FrontAndDequeue()
{
    ElementType res = Front();
    Dequeue();
    return res;
}
