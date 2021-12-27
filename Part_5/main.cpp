#include "Header.h"
#include <conio.h>
#include<iostream>
using namespace std;


template <typename T>
Deque<T>::Deque<T>(int count)
{
	this->count = 0;
	this->size = count;
	front = -1;
	back = -1;
	arr = new T[count];
}

template <typename T>
Deque<T>& Deque<T>::operator=(Deque&& other)
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

template <typename T>
Deque<T>::~Deque<T>()
{
	delete[] arr;
}

template <typename T>
int Deque<T>::GetSize()
{
	return count;
}

template <typename T>
void Deque<T>::pushFront(const T a)
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
}

template <typename T>
void Deque<T>::pushBack(const T a)
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


}

template <typename T>
void Deque<T>::popFront(T& a)
{
	if (front == -1)
	{
		throw NoElementsException("Deck is Empty!");
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
	}
}

template <typename T>
void Deque<T>::popBack(T& a)
{
	if (front == -1)
	{
		throw NoElementsException("Deck is Empty!");
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
	}
}

template <typename T>
void Deque<T>::peekFront(T& a)
{
	if (front == -1)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = arr[front];
	}
}

template <typename T>
void Deque<T>::peekBack(T& a)
{
	if (back == -1)
	{
		throw NoElementsException("Deck is Empty!");
	}
	else
	{
		a = arr[back];
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	int dsize;
	double b;
	bool flag = true;
	cout << "������� ������ ����\n";
	cin >> dsize;
	Deque<double>* a;
	a = new Deque<double>(dsize);
	while (flag)
	{
		cout << "1. �������� ������� � ������ ����\n";
		cout << "2. �������� ������� �� ������ ����\n";
		cout << "3. �������� ������� � ����� ����\n";
		cout << "4. �������� ������� �� ����� ����\n";
		cout << "5. ���������� ������� � ����� ����\n";
		cout << "6. ���������� ������� �� ����� ����\n";
		cout << "7. �����\n";
		switch (_getch()) 
		{
			case '1':
				cout << "�������� �������: ";
				cin >> b;
				a->pushFront(b);
				cout << "������� �������� � ������" << endl;
				break;
			case '2':
				try 
				{
					a->popFront(b);
					cout << "���������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "��� ����\n";
				}
				break;
			case '3':
				cout << "�������� �������: ";
				cin >> b;
					a->pushBack(b);
					cout << "������� �������� � ����� " << endl;

				break;
			case '4':
				try
				{
					a->popBack(b);
					cout << "���������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "��� ����\n";
				}
				break;
			case '5':
				try 
				{
					a->peekFront(b);
					cout << "���������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "��� ����\n";
				}
				break;
			case '6':
				try
				{
					a->peekBack(b);
					cout << "���������� ������� " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "��� ����\n";
				}
				break;
			case '7':
				flag = false;
				break;

		}
	}

}