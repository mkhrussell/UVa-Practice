// #define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
// #include <iostream>

// using namespace std;

const int N_LIMIT = 35;
const int T_LIMIT = 1005;

int T, W, N;
int treasureDepth[N_LIMIT];
int treasureValue[N_LIMIT];
int treasureTimeCost[N_LIMIT];

int maxValue; // Optimal value
int numTakenTreasure;

int tmpTaken[N_LIMIT];
int finalTaken[N_LIMIT]; // Optimal path
int savedSum[N_LIMIT][T_LIMIT]; // cache for DP

void takeNextTreasure(int n, int remainingTime, int sum)
{
	if (n == N)
	{
		if (sum > maxValue)
		{
			maxValue = sum;
			numTakenTreasure = 0;
			for (int i = 0; i < N; i++)
			{
				finalTaken[i] = tmpTaken[i];
				if(finalTaken[i]) numTakenTreasure++;
			}
		}

		return;
	}

	// Left Node: Taking the current item	
	if (remainingTime >= treasureTimeCost[n])
	{
		tmpTaken[n] = 1;
		takeNextTreasure(n + 1, remainingTime - treasureTimeCost[n], sum + treasureValue[n]);
	}

	// Right Node: Not taking the current item
	tmpTaken[n] = 0;
	takeNextTreasure(n + 1, remainingTime, sum);

	return;
}

void init()
{
	maxValue = 0;
	numTakenTreasure = 0;
	for (int i = 0; i < N_LIMIT; i++)
	{
		for (int j = 0; j < T_LIMIT; j++)
		{
			savedSum[i][j] = -1;
		}
	}
}

void printCase()
{
	printf("%d\n", maxValue);
	if (maxValue) {
		printf("%d\n", numTakenTreasure);
		for (int i = 0; i < N; i++)
		{
			if (finalTaken[i])
			{
				printf("%d %d\n", treasureDepth[i], treasureValue[i]);
			}
		}
	}
	else
	{
		printf("0\n");
	}	
}

void solveCase()
{
	takeNextTreasure(0, T, 0);
}

void readCase()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &treasureDepth[i], &treasureValue[i]);
		treasureTimeCost[i] = 3 * W * treasureDepth[i]; // td + ta
	}
}

int main()
{
	int nCase = 0;
	while (scanf("%d %d", &T, &W) != EOF)
	{
		if (nCase)
			printf("\n");

		nCase++;
		init();
		readCase();
		solveCase();		
		printCase();
	}

	return 0;
}