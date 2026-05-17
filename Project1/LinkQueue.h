#pragma once
#include "QueueBase.h"

struct QueueNode
{
    ElementType data;
    QueueNode* next;
    QueueNode(ElementType x) : data(x), next(nullptr) {}
};

class LinkQueue : public QueueBase
{
private:
    QueueNode* front;
    QueueNode* rear;
public:
    LinkQueue();
    ~LinkQueue() override;
    bool IsEmpty() const override;
    bool IsFull() const override;
    void MakeEmpty() override;
    void Enqueue(ElementType x) override;
    ElementType Front() const override;
    void Dequeue() override;
    ElementType FrontAndDequeue() override;
};

