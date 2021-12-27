#include "Header.h"


Deque::Deque(int count)
{
	this->count = 0;
	this->size = count;
	front = -1;
	back = -1;
	arr = new int[count];
}

Deque& Deque::operator=(Deque &&other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] arr;
	arr = other.arr;
	count = other.count;
	other.arr = nullptr;
	return *this;
}

Deque::~Deque()
{
	delete[] arr;
}

int Deque::GetSize()
{
	return count;
}

bool Deque::pushFront(const int a)
{
	if (count)
	{
		if ((--front) < 0)
		{
			front = size - 1;
		}
	}
	else
	{
		front = back = 0;
	}
	arr[front] = a;
	count++;
	return true;
}


bool Deque::pushBack(const int a)
{
	if (back >= count - 1)
	{
		return false;
	}
	else
	{
		if (front == -1)
		{
			front++;
			back++;
		}
		else
		back = back + 1;
		arr[back] = a;
		++count;
		return true;
	}

}

bool Deque::popFront(int& a)
{
	if (front == -1)
	{
		return false;
	}
	else
	{
		a = arr[front];
		if (front == back)
		{
			front = back = -1;
		}
		else
		{
			front = front + 1;
		}
		--count;
		return true;
	}	
}

bool Deque::popBack(int& a)
{
	if (front == -1)
	{
		return false;
	}
	else
	{
		a = arr[back];
		if (front == back)
		{
			front = back = -1;
		}
		else 
		{
			back = back - 1;
		}
		return true;
	}
}


bool Deque::peekFront(int& a)
{
	if (front == -1)
	{
		return false;
	}
	else
	{
		a = arr[front];
		return true;
	}
}

bool Deque::peekBack(int& a)
{
	if (back == -1)
	{
		return false;
	}
	else
	{
		a = arr[back];
		return true;
	}
}