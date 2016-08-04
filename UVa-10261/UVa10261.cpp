/*
This problem is a subset generation problem.
Read the article: http://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
*/

#include <iostream>
#include <cstdio>

int T;
int nCase;

int N;
int oneSideSize;
int bothSideSize;

int inputQueue[100];
int finalTaken[100];

int tmpSet[100];
int tmpTaken[100];
int tmpSum = 0;

int minDiff = 500000;

int myAbs(int a)
{
	return a >= 0 ? a : -a;
}

void backtrack(int level, int N, int remainder)
{
	if (level == N)
	{
		int setOneSum = 0, setTwoSum = 0;
		
		for (int i = 0; i < N; i++)
		{
			if (tmpTaken[i] == 1)
			{
				setOneSum += tmpSet[i];
			}
		}

		setTwoSum = tmpSum - setOneSum;		
		int diff = myAbs(setTwoSum - setOneSum);

		if (diff < minDiff)
		{
			minDiff = diff;
			for (int i = 0; i < N; i++)
			{
				if (tmpTaken[i] == tmpTaken[0])
					finalTaken[i] = 1;
				else
					finalTaken[i] = 0;
			}
		}

		// Reset
		for (int i = 0; i < N; i++)
			tmpTaken[i] = 0;
	}
	else
	{
		if (remainder - tmpSet[level] >= 0)
		{
			tmpTaken[level] = 1;
			backtrack(level + 1, N, remainder - tmpSet[level]);
		}

		tmpTaken[level] = 0;
		backtrack(level + 1, N, remainder);
	}
}

void makeTwoSet(int setSize, int setSum)
{
	backtrack(0, setSize, setSum);
}

void reset()
{
	tmpSum = 0;
}

int main(int argc, char **argv)
{
	freopen("critical_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &T);

	nCase = 1;
	while (nCase <= T)
	{
		if (nCase)
			printf("\n");

		scanf("%d", &oneSideSize);
		oneSideSize = oneSideSize * 100;
		bothSideSize = oneSideSize * 2;

		int carLen;
		while (scanf("%d", &carLen) && carLen > 0)
		{
			inputQueue[N] = carLen;
			N++;
		}

		int tmpRem = bothSideSize; // Ferry capacity
		tmpSum = 0;
		int tmpN = 0;
		for (int i = 0; tmpRem >= inputQueue[i] ; i++, tmpN++)
		{
			tmpSet[i] = inputQueue[i];
			tmpRem = tmpRem - inputQueue[i];
			tmpSum += inputQueue[i];
		}

		makeTwoSet(tmpN, oneSideSize); // Create two equal set
		
		printf("%d\n", tmpN);
		int set1 = 0, set2 = 0;
		for (int n = 0; n < tmpN; n++)
		{
			if (finalTaken[n] == 1)
			{
				printf("port");
				//set1 += inputQueue[n];
			}
			else
			{
				printf("starboard");
				//set2 += inputQueue[n];
			}
			printf("\n");
		}

		nCase++;
	}

	return 0;
}
