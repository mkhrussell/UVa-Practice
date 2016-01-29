#define ST_SIZE 100
#define ST_INF 100000000

class Stack {
public:
	Stack() { /*blank*/ }
	~Stack() { /*blank*/ }
	bool isFull() { return (__top == __SIZE); }
	bool isEmpty() { return (__top < 0); }
	void push(int value)
	{
		if (isFull())
		{
			std::cout << "STACK OVERFLOW" << std::endl;
		}
		else
		{
			if (isEmpty()) { __top = 0; }
			else{ __top++; }

			__container[__top] = value;
		}
	}

	int top()
	{
		if (!isEmpty())
		{
			return __container[__top];
		}

		return ST_INF;
	}

	void pop()
	{
		if (!isEmpty())
		{
			__top--;
		}
	}

private:
	const int __SIZE = ST_SIZE - 1;
	int __container[ST_SIZE];
	int __top = -1;
};
