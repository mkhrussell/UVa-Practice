#define Q_SIZE 10000
#define Q_INF 100000000

class Queue {
public:
	Queue() { /*Blank*/ }
	~Queue() { /*Blank*/ }

	bool isFull() { return ((__back + 1) % __SIZE == __front); }
	bool isEmpty() { return (__front == __back); }

	void push(int value)
	{
		if (!isFull())
		{
			__container[__back] = value;
			__back = (__back + 1) % __SIZE;
		}
	}

	void pop()
	{
		if (!isEmpty())
		{
			__front = (__front + 1) % __SIZE;
		}
	}

	int front()
	{
		if (!isEmpty())
		{
			return __container[__front];
		}
		return Q_INF; // Always compare this after poping the element from the Queue
	}

private:
	int __front = 0;
	int __back = 0;
	int __container[Q_SIZE + 1];
	const int __SIZE = Q_SIZE + 1;
};
