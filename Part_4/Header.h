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

template <typename T>
class Deque
{
public:
	Deque(int count);
	Deque& operator=(Deque&& other);
	~Deque();
	int GetSize();
	void pushFront(const T a);
	void pushBack(const T a);
	void popFront(T& a);
	void popBack(T& a);
	void peekFront(T& a);
	void peekBack(T& a);
private:
	T* arr;
	int back;
	int front;
	int count;
	int size;
};