#pragma once
typedef int ElementType;

// 队列抽象基类
class QueueBase
{
public:
    // 纯虚函数 统一接口
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual void MakeEmpty() = 0;
    virtual void Enqueue(ElementType x) = 0;
    virtual ElementType Front() const = 0;
    virtual void Dequeue() = 0;
    virtual ElementType FrontAndDequeue() = 0;
    virtual ~QueueBase() = default;
};

