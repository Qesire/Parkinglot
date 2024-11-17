#ifndef QUEUEF_H_
#define QUEUEF_H_
#include "Announcements.h"//改为CPP中实现

inline void initWaitingQueue(WaitingQueue& q, int m)
{
	q.front = q.rear = new QueueNode;
	q.front->next = NULL;
	q.number = 0;
	q.maxsize = m;
}

inline void deleteWaitingQueue(WaitingQueue& q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		delete q.front;
		q.front = q.rear;
	}
}

inline void Enqueue(WaitingQueue& q, Car e)
{
	Queueptr p = new QueueNode;
	p->elem = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	q.number++;
}

inline bool Dequeue(WaitingQueue& q, Car& e)
{
	if (q.front == q.rear)
	{
		return 0;
	}
	Queueptr p = q.front->next;
	q.front->next = p->next;
	e = p->elem;
	if (q.rear == p)
	{
		q.rear = q.front;
	}
	delete p;
	q.number--;
	return 1;
}

inline bool isFullQueue(WaitingQueue q)
{
	if (q.number == q.maxsize)
		return 1;
	return 0;
}

inline bool isEmptyQueue(WaitingQueue q)
{
	if (q.front == q.rear)
		return 1;
	return 0;
}

#endif
