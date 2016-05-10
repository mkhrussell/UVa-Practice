#include <cstdio>

const int SET_SIZE = 101;
int myData[SET_SIZE];

int N, superSum;
int saved[SET_SIZE][50001];

void init()
{
	for (int i = 0; i < SET_SIZE; i++)
	{
		for (int j = 0; j < 50001; j++)
		{
			saved[i][j] = -1;
		}
	}
}

int myAbs(int num)
{
	return num >= 0 ? num : -num;
}

int myMin(int left, int right)
{
	return left < right ? left : right;
}

int takeNext(int i, int taken)
{
	int ret, next;
	if (i >= N)
	{
		ret = myAbs(taken - (superSum - taken));
		return ret;
	}

	ret = saved[i][taken];
	if (ret >= 0) return ret; // Return saved

	next = i + 1;
	int withCurrent = takeNext(next, taken + myData[i]);
	int withoutCurrent = takeNext(next, taken);
	ret = myMin(withCurrent, withoutCurrent);
	saved[i][taken] = ret; // Save

	return ret;
}

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int C;
	scanf("%d", &C);
	while (C--)
	{
		superSum = 0; // Init
		init();

		scanf("%d", &N);
		for (int i = N - 1; i >= 0; i--)
		{
			scanf("%d", &myData[i]);
			superSum += myData[i];
		}

		int result = takeNext(0, 0);
		printf("%d\n", result);
	}

	return 0;
}
