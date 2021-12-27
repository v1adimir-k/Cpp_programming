#include <iostream>
#include "AbstractDeque.h"
using namespace std;

class NoElementsException :public exception
{
public:
	NoElementsException(const char* msg) :
		exception(msg) {}
};

class OverflowException :public exception
{
public:
	OverflowException(const char* msg) :
		exception(msg) {}
};

template <typename T>
class Deque:AbstractDeque<T>
{
public:
	Deque(int count);
	Deque& operator=(Deque&& other);
	~Deque();
	int GetSize()override;
	void pushFront(const T a)override;
	void pushBack (const T a)override;
	void popFront(T& a)override;
	void popBack(T& a)override;
	void peekFront(T& a)override;
	void peekBack(T& a)override;
private:
	T* arr;
	int back;
	int front;
	int count;
	int size;
};