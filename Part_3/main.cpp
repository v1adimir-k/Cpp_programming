#include "Header.h"
#include <conio.h>
#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int b, dsize;
	bool flag = true;
	cout << "Введите размер дека\n";
	cin >> dsize;
	Deque* a;
	a = new Deque(dsize);
	while (flag)
	{
		cout << "1. Добавить элемент в начало дека\n";
		cout << "2. Получить элемент из начала дека\n";
		cout << "3. Добавить элемент в конец дека\n";
		cout << "4. Получить элемент из конца дека\n";
		cout << "5. Посмотреть элемент в конец дека\n";
		cout << "6. Посмотреть элемент из конца дека\n";
		cout << "7. Выход\n";
		switch (_getch()) 
		{
			case '1':
				cout << "Добавить элемент: ";
				cin >> b;
				a->pushFront(b);
				cout << "Элемент добавлен в начало" << endl;
				break;
			case '2':
				try 
				{
					a->popFront(b);
					cout << "Полученный элемент " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "Дек пуст\n";
				}
				break;
			case '3':
				cout << "Добавить элемент: ";
				cin >> b;
					a->pushBack(b);
					cout << "Элемент добавлен в конец " << endl;

				break;
			case '4':
				try
				{
					a->popBack(b);
					cout << "Полученный элемент " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "Дек пуст\n";
				}
				break;
			case '5':
				try 
				{
					a->peekFront(b);
					cout << "Полученный элемент " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "Дек пуст\n";
				}
				break;
			case '6':
				try
				{
					a->peekBack(b);
					cout << "Полученный элемент " << b << endl;
				}
				catch (NoElementsException ex)
				{
					cout << "Дек пуст\n";
				}
				break;
			case '7':
				flag = false;
				break;

		}
	}

}