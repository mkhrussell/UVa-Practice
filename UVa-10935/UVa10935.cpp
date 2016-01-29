#include <iostream>
#include <cstdio>

using namespace std;


int discardedArray[51];
int SIZE = 51;

//Datastructure
int tail = 0;
int head = 0;
int queueArray[51];
void init()
{
	for (int i = 0; i < 51; i++)
		queueArray[i] = 0;

	tail = 0;
	head = 0;


	for (int i = 0; i < 51; i++)
		discardedArray[i] = 0;
}

bool isFull()
{
	return ((tail + 1) % SIZE == head);
}

bool isEmpty()
{
	return (head == tail);
}

void enqueue(int value)
{
	if (!isFull()){
		queueArray[tail] = value;
		tail = (tail + 1) % SIZE;
	}
}

void dequeue()
{
	if (!isEmpty())
	{
		head = (head + 1) % SIZE;
	}
}

int top()
{
	if (!isEmpty())
	{
		return queueArray[head];
	}
}



//End Datastructure

int main(int argc, char **argv)
{
	//freopen("../res/sample-input.txt", "r", stdin);
    //freopen("../res/output.txt", "w", stdout);
    
	int nCase = 1;
	int deckSize;	
	for (;; nCase++)
	{
		init(); //Init

		cin >> deckSize;
		if (deckSize == 0)
			break;

		for (int card = 1; card <= deckSize; card++)
		{
			enqueue(card);
		}

		//Solve
		int disCount = 0;
		while (!isEmpty())
		{
			discardedArray[disCount++] = top();
			dequeue();
			enqueue(top());
			dequeue();
		}

		//Print
		int i = 0;
		cout << "Discarded cards:";
		for (; i < disCount - 1; i++)
		{
			if (i == (disCount - 2))
				cout << " " << discardedArray[i];
			else
				cout << " " << discardedArray[i] << ",";
		}
		cout << endl;

		cout << "Remaining card: " << discardedArray[i] << endl;
	}

	return 0;
}
