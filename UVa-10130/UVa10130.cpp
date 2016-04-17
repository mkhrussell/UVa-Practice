#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
//#include <iostream>

const int N_LIMIT = 1005;
const int G_LIMIT = 105;
const int MW_LIMIT = 35;

int T, N, G;
int itemPrices[N_LIMIT];
int itemWeights[N_LIMIT];
int persionWeightLimits[G_LIMIT];

int savedTotalPrices[N_LIMIT][MW_LIMIT];
int result;

int myMax(int left, int right)
{
	return left > right ? left : right;
}

void init()
{
	result = 0;
	for (int i = 0; i < N_LIMIT; i++)
	{
		for (int j = 0; j < MW_LIMIT; j++)
		{
			savedTotalPrices[i][j] = -1;
		}
	}
}

int takeNextItem(int currItem, int remainingWeight)
{
	int bestValue = 0;
	if (currItem >= N)
	{
		return bestValue;
	}

	bestValue = savedTotalPrices[currItem][remainingWeight]; // Use saved value
	if (bestValue != -1)
	{
		return bestValue;
	}
	
	bestValue = takeNextItem(currItem + 1, remainingWeight); // Without taking current item
	if (remainingWeight >= itemWeights[currItem])
	{
		int withCurrItem = itemPrices[currItem] + takeNextItem(currItem + 1, remainingWeight - itemWeights[currItem]);
		bestValue = myMax(bestValue, withCurrItem);
	}

	savedTotalPrices[currItem][remainingWeight] = bestValue; // Save value for future use
	
	return bestValue;
}

void printCase()
{
	printf("%d\n", result);
}

/*
void printInput()
{
	printf("Case # %d\n", T);
	printf("%d\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", itemPrices[i], itemWeights[i]);
	}

	printf("%d\n", G);
	for (int i = 0; i < G; i++)
	{
		printf("%d\n", persionWeightLimits[i]);
	}

	printf("//\n\n");
}
*/

void solveCase()
{
	for (int i = 0; i < G; i++)
	{
		result += takeNextItem(0, persionWeightLimits[i]);
	}	
}

void readCase()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &itemPrices[i], &itemWeights[i]);
	}

	scanf("%d", &G);
	for (int i = 0; i < G; i++)
	{
		scanf("%d", &persionWeightLimits[i]);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		init();
		readCase();
		//printInput();
		solveCase();
		printCase();
	}

	return 0;
}
