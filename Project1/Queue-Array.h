#ifndef Queue_Array_h
#define Queue_Array_h
#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct QueueRecord* Queue;
int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType FrontAndDequeue(Queue Q);
int Succ(int Value, Queue Q);
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType* Array;
};
#endif