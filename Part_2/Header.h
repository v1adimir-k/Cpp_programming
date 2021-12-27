class Deque
{
public:
	Deque(int count);
	Deque& operator=(Deque&& other);
	~Deque();
	int GetSize();
	bool pushFront(const int a);
	bool pushBack(const int a);
	bool popFront(int& a);
	bool popBack(int& a);
	bool peekFront(int& a);
	bool peekBack(int& a);
private:
	int* arr;
	int back;
	int front;
	int count;
	int size;
};