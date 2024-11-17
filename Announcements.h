#ifndef ANNOUNCEMENTS_H_
#define ANNOUNCEMENTS_H_



#pragma once
#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

typedef struct Car
{
	int carNumber;
	int arivalTime;
	int departTime;
}Car, * Carptr;

class ParkingStack
{
public:
	Carptr elem;
	int stacksize;
	int top;//栈顶指针
public:
	void initParkingStack(ParkingStack& s, int n);
	void deleteParkingStack(ParkingStack& s);
	void Push(ParkingStack& s, Car e);
	bool Pop(ParkingStack& s, Car& e);
	bool isFullStack(ParkingStack s);
	bool isEmptyStack(ParkingStack s);
};

typedef struct QueueNode
{
	Car elem;
	QueueNode* next;
}QueueNode, * Queueptr;

class WaitingQueue {
public:
	Queueptr front;
	Queueptr rear;
	int number;//队列中元素个数
	int maxsize;//队列中元素个数上限
public:
	void initWaitingQueue(WaitingQueue& q, int m);
	void deleteWaitingQueue(WaitingQueue& q);
	void Enqueue(WaitingQueue& q, Car e);
	bool Dequeue(WaitingQueue& q, Car& e);
	bool isFullQueue(WaitingQueue q);
	bool isEmptyQueue(WaitingQueue q);

};


class Ccar {

public:
	int findCar(ParkingStack s, WaitingQueue q, int number);
	bool CarIn(ParkingStack& s, WaitingQueue& q, int number, int time);
	bool CarOut(ParkingStack& s, WaitingQueue& q, int number, int time, int n, int p);
	void CheckParking(ParkingStack s);
	void CheckWaiting(WaitingQueue q);
};
#endif // !1
