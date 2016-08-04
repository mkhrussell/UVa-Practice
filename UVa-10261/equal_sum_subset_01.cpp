/*
This problem is a subset generation problem.
Read the article: http://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
*/

/*
#include <iostream>
#include <cstdio>

int T;
int nCase;

int N;
int ferryLen;

int inputQueue[100];

int tmpSet[100];
int tmpTaken[100];

int minDiff = 500000;
int tmpSetOne[100];
int tmpSetTwo[100];

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

void backtrack(int tmpSet[], int level, int N, int remainder)
{
	if (level == N || remainder <= 0)
	{
		int setOneSum = 0, setTwoSum = 0;
		for (int i = 0; i < N; i++)
		{
			if (tmpTaken[i] == 1)
			{
				setOneSum += tmpSet[i];
			}
			else
			{
				setTwoSum += tmpSet[i];
			}
		}

		int diff = myAbs(setOneSum - setTwoSum);
		if (diff < minDiff)
		{
			minDiff = diff;
			int i = 0;
			int m = 0, n = 0;
			for (; i < N; i++)
			{
				if (tmpTaken[i] == 1)
				{
					tmpSetOne[m++] = tmpSet[i];
				}
				else
				{
					tmpSetTwo[n++] = tmpSet[i];
				}
			}

			for (; m < N; m++)
				tmpSetOne[m++] = 0;

			for (; n < N; n++)
				tmpSetTwo[n++] = 0;
		}

		for (int i = 0; i < N; i++)
			tmpTaken[i] = 0;
	}
	else
	{
		tmpTaken[level] = 1;
		backtrack(tmpSet, level + 1, N, remainder - tmpSet[level]);

		tmpTaken[level] = 0;
		backtrack(tmpSet, level + 1, N, remainder);
	}
}

void makeTwoSet(int tmpSet[], int setSize, int setSum)
{
	backtrack(tmpSet, 0, setSize, setSum);
}

int main(int argc, char **argv)
{
	freopen("sample-input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	nCase = 1;
	while (nCase <= T)
	{
		scanf("%d", &ferryLen);
		ferryLen = ferryLen * 100;

		int carLen;
		while (scanf("%d", &carLen) && carLen > 0)
		{
			inputQueue[N] = carLen;
			N++;
		}

		int tmpRem = ferryLen * 2; // Ferry capacity
		int tmpN = 0;
		for (int i = 0; tmpRem >= inputQueue[i]; i++, tmpN++)
		{
			tmpSet[i] = inputQueue[i];
			tmpRem = tmpRem - inputQueue[i];
		}

		makeTwoSet(tmpSet, tmpN, ferryLen); // Create two equal set

		printf("Set 1:\n");
		for (int m = 0; m < N; m++)
			printf("%d ", tmpSetOne[m]);

		printf("\n");

		printf("Set 2:\n");
		for (int n = 0; n < N; n++)
			printf("%d ", tmpSetTwo[n]);

		printf("\n");

		nCase++;
	}

	return 0;
}

*/