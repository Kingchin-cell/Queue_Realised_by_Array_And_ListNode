#pragma once
#include "QueueBase.h"

class ArrayQueue : public QueueBase
{
private:
    int Capacity;
    int FrontIdx;
    int RearIdx;
    int Size;
    ElementType* Array;
    int Succ(int val);
public:
    ArrayQueue(int maxElem);
    ~ArrayQueue() override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    void MakeEmpty() override;
    void Enqueue(ElementType x) override;
    ElementType Front() const override;
    void Dequeue() override;
    ElementType FrontAndDequeue() override;
};

