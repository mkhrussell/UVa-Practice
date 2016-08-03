/*

#include <iostream>
#include <cstdio>

#define NMAX 100
#define SET_LIMIT 100

void backtrack(int a[], int k, int n, int input_set[])
{
	int ncandidates = 2; // Choice

	if (k == n)
	{
		printf("{");
		for (int i = 0; i < k; i++)
		{
			if (a[i] == 1)
			{
				printf(" %d", input_set[i]);
			}
		}
		printf(" }\n");
	}
	else
	{
		for (int i = 0; i < ncandidates; i++)
		{
			a[k] = i;
			backtrack(a, k + 1, n, input_set);
		}
	}
}

void generate_subsets(int n, int input_set[])
{
	int a[SET_LIMIT];
	backtrack(a, 0, n, input_set);
}

int main(int argc, char **argv)
{
	int input_set[NMAX];
	input_set[0] = 2500;
	input_set[1] = 3000;
	input_set[2] = 1000;
	input_set[3] = 1000;
	input_set[4] = 1500;
	input_set[5] = 700;
	input_set[6] = 800;

	generate_subsets(7, input_set);
	return 0;
}

*/