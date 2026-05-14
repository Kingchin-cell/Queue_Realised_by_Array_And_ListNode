#define _CRT_SECURE_NO_WARNINGS
#include"Queue-Array.h"
static int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
static int IsFull(Queue Q)
{
	if (Q->Size == Q->Capacity)
		return true;
	return false;
}
static void MakeEmpty(Queue Q)
{
	Q->Front = 1;
	Q->Size = 0;
	Q->Rear = 0;
}
static Queue CreateQueue(int MaxElements)
{
	Queue Q = new QueueRecord;
	Q->Array = new int[MaxElements];
	Q->Capacity = MaxElements;
	MakeEmpty(Q);
	return Q;
}
static void DisposeQueue(Queue Q)
{
	if (Q == NULL)
	{
		return;
	}
	delete[] Q->Array;
	delete Q;
}
static int Succ(int Value, Queue Q)
{
	Value++;
	if (Value == Q->Capacity)
		Value = 0;
	return Value;
}
static void Enqueue(ElementType X, Queue Q)
{
	if (IsFull(Q))
	{
		cout << "空间已满,入队失败" << endl;
		exit(0);
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}
static ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "队列为空，退队失败" << endl;
		exit(0);
	}
	else
	{
		int tmp = Q->Array[Q->Front];
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
		return tmp;
	}
}
void test01()
{
	Queue Q = CreateQueue(5);
	Enqueue(10, Q);
	Enqueue(20, Q);
	Enqueue(30, Q);
	Enqueue(40, Q);
	Enqueue(50, Q);
	while (!IsEmpty(Q))
	{
		cout << FrontAndDequeue(Q) << endl;
	}
	Enqueue(100, Q);
	MakeEmpty(Q);
	DisposeQueue(Q);



}
//int main()
//{
//	test01();
//	return 0;
//}








