#include <iostream>
#include <string>
#include <queue>

#include <cstdio>

#define N_MAX 10001

using namespace std;

struct Car
{
	int pos = -1;
	int wtTime = -1;
} defaultCar;

queue <Car> leftQue;
queue <Car> rightQue;

int waitingTimes[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		waitingTimes[i] = -1;
	}
}

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("redirect.txt", "w", stdout);

	int C;
	cin >> C; //read case limit
	for (int nCase = 1; nCase <= C; nCase++)
	{
		int N, T, M;
		cin >> N >> T >> M; //load limits
		for (int m = 0; m < M; m++)
		{
			int wtTime;
			string wtSide;
			cin >> wtTime >> wtSide;

			Car newCar;
			newCar.pos = m;
			newCar.wtTime = wtTime;
			if (wtSide.compare("left") == 0)
			{
				leftQue.push(newCar);
			}
			else
			{
				rightQue.push(newCar);
			}
		}

		init(); // Init previous case's result

		bool inLeftSide = true; //initial side is left
		int eplasedTime = 0;


		if (!leftQue.empty())
		{
			Car &tmpCar = leftQue.front();
			if (tmpCar.pos == 0)
			{
				eplasedTime = tmpCar.wtTime;
				inLeftSide = true;
			}
		}

		if (!rightQue.empty())
		{
			Car &tmpCar = rightQue.front();
			if (tmpCar.pos == 0)
			{
				eplasedTime = tmpCar.wtTime;
				inLeftSide = false;
			}
		}

		while (!leftQue.empty() || !rightQue.empty())
		{
			int numLeftCars = 0;
			while (!leftQue.empty() && numLeftCars < N)
			{
				Car &tmpCar = leftQue.front();
				if (tmpCar.wtTime > eplasedTime && numLeftCars == 0)
				{
					eplasedTime = tmpCar.wtTime;
				}

				waitingTimes[tmpCar.pos] = eplasedTime + T;
				leftQue.pop();
				numLeftCars++;
			}

			eplasedTime += T;

			int numRightCars = 0;
			while (!rightQue.empty() && numRightCars < N)
			{
				Car &tmpCar = rightQue.front();
				if (tmpCar.wtTime > eplasedTime && numRightCars == 0 && !leftQue.empty())
				{
					eplasedTime = tmpCar.wtTime;
				}else if(tmpCar.wtTime > eplasedTime && numRightCars == 0 && !leftQue.empty())

				waitingTimes[tmpCar.pos] = eplasedTime + T;
				rightQue.pop();
				numRightCars++;
			}

			eplasedTime += T;
		}

		// Print results
		for (int pos = 0; pos < M; pos++)
		{
			cout << waitingTimes[pos] << endl;
		}

		if (nCase < C) //No extra new line after last case
			cout << endl;
	}

	return 0;
}
