#define _CRT_SECURE_NO_WARNINGS
#include "ArrayQueue.h"
#include <cassert>
#include <cstdlib>

int ArrayQueue::Succ(int val)
{
    if (++val == Capacity + 1)
        val = 1;
    return val;
}

ArrayQueue::ArrayQueue(int maxElem)
{
    Capacity = maxElem;
    FrontIdx = 1;
    RearIdx = 0;
    Size = 0;
    Array = new ElementType[Capacity + 1];
}

ArrayQueue::~ArrayQueue()
{
    delete[] Array;
}

bool ArrayQueue::IsEmpty() const
{
    return Size == 0;
}

bool ArrayQueue::IsFull() const
{
    return Size == Capacity;
}

void ArrayQueue::MakeEmpty()
{
    FrontIdx = 1;
    RearIdx = 0;
    Size = 0;
}

void ArrayQueue::Enqueue(ElementType x)
{
    assert(!IsFull());
    Size++;
    RearIdx = Succ(RearIdx);
    Array[RearIdx] = x;
}

ElementType ArrayQueue::Front() const
{
    assert(!IsEmpty());
    return Array[FrontIdx];
}

void ArrayQueue::Dequeue()
{
    assert(!IsEmpty());
    Size--;
    FrontIdx = Succ(FrontIdx);
}

ElementType ArrayQueue::FrontAndDequeue()
{
    ElementType res = Front();
    Dequeue();
    return res;
}
