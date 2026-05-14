#define _CRT_SECURE_NO_WARNINGS
#include"Queue-ListNode.h"
static int IsEmpty(Queue Q)
{
	if (Q->Front == Q->Rear)
		return true;
	return false;
}
static Queue CreateQueue(void)
{
	Queue Q = new QueueRecord;
	PtrToNode Node = new QueueNode;
	Node->Next = NULL;
	Q->Front = Node;
	Q->Rear = Node;
	return Q;
}
static void DisposeQueue(Queue Q)
{
	while (Q->Front != Q->Rear)
	{
		PtrToNode tmp = Q->Front;
		Q->Front = Q->Front->Next;
		delete tmp;
	}
}
static void MakeEmpty(Queue Q)
{
	PtrToNode pcur = Q->Front->Next;
	while (pcur != NULL)
	{
		PtrToNode tmp = pcur;
		pcur = pcur->Next;
		delete tmp;
	}
	Q->Rear = Q->Front;
	Q->Front->Next = NULL;
}
static void Enqueue(ElementType X, Queue Q)
{
	PtrToNode newNode = new QueueNode;
	if (newNode == NULL)
	{
		cout << "没空间了！" << endl;
		exit(0);
	}
	newNode->Element = X;
	newNode->Next = NULL;
	Q->Rear->Next = newNode;
	Q->Rear = newNode;
}
static ElementType Front(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "没有元素" << endl;
		exit(0);
	}
	return Q->Front->Next->Element;
}
static void Dequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "退队失败" << endl;
		exit(0);
	}
	else
	{
		PtrToNode tmp = Q->Front;
		Q->Front = Q->Front->Next;
		delete tmp;
	}
}
ElementType FrontAndDequeue(Queue Q)
{
	if (IsEmpty(Q))
	{
		cout << "退队失败" << endl;
		exit(0);
	}
	else
	{
		PtrToNode tmp = Q->Front;
		int x = tmp->Next->Element;
		Q->Front = Q->Front->Next;
		delete tmp;
		return x;
	}
}
void test02()
{
	Queue Q = CreateQueue();
	Enqueue(10, Q);
	Enqueue(20, Q);
	Enqueue(30, Q);
	while (!IsEmpty(Q))
	{
		cout << FrontAndDequeue(Q) << endl;
	}
	Enqueue(10, Q);
	int a=Front(Q);
	cout << a << endl;
	MakeEmpty(Q);
	Front(Q);
}
int main()
{
	test02();
	return 0;
}







