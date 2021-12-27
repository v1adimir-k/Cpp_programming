#include <iostream>

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


class Deque
{
public:
	Deque(int count);
	Deque& operator=(Deque&& other);
	~Deque();
	int GetSize();
	void pushFront(const int a);
	void pushBack(const int a);
	void popFront(int& a);
	void popBack(int& a);
	void peekFront(int& a);
	void peekBack(int& a);
private:
	int* arr;
	int back;
	int front;
	int count;
	int size;
};