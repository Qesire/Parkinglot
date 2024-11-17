#ifndef STACKF_H_
#define STACKF_H_

#include "Announcements.h"

inline void initParkingStack(ParkingStack& s, int n)
{
	s.elem = new Car[n];
	s.stacksize = n;
	s.top = -1;
}

inline void deleteParkingStack(ParkingStack& s)
{
	delete[]s.elem;
	s.top = -1;
	s.stacksize = 0;
}

inline void Push(ParkingStack& s, Car e)
{
	s.elem[++s.top] = e;
}

inline bool Pop(ParkingStack& s, Car& e)
{
	if (s.top == -1)
		return 0;
	e = s.elem[s.top--];
	return 1;
}

inline bool isFullStack(ParkingStack s)
{
	if (s.top == s.stacksize - 1)
		return 1;
	return 0;
}

inline bool isEmptyStack(ParkingStack s)
{
	if (s.top == -1)
		return 1;
	return 0;
}

#endif

