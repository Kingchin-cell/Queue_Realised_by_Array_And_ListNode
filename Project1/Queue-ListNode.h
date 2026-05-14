#ifndef Queue_ListNode_h
#define Queue_ListNode_h
#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct QueueNode* PtrToNode;
typedef struct QueueRecord* Queue;
struct QueueNode
{
	ElementType Element;
	PtrToNode Next;
};
struct QueueRecord
{
	PtrToNode Front;
	PtrToNode Rear;
};
int IsEmpty(Queue Q);
Queue CreateQueue(void);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
#endif