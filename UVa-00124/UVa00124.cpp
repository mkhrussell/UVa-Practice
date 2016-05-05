#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

#define MAX_VARS (30)

int VarLength;
char Vars[MAX_VARS];
char Result[MAX_VARS];

int Visited[MAX_VARS];
int OrderMatrix[MAX_VARS][MAX_VARS];

void init()
{
	VarLength = 0;
	for (int i = 0; i < MAX_VARS; i++)
	{
		Vars[i] = '\0';
		Visited[i] = 0;
		for (int j = 0; j < MAX_VARS; j++)
		{
			OrderMatrix[i][j] = -1;
		}
	}
}

bool isValidVar(char var)
{
	return (var >= 'a' & var <= 'z');
}

void print()
{
	for (int i = 0; i < VarLength; i++)
		printf("%c", Result[i]);
	printf("\n");
}

void nextPermutation(int level)
{
	if (level == VarLength)
	{
		print(); //Print
		return;
	}

	for (int j = 0; j < VarLength; j++)
	{
		bool IsValid = true;
		for (int k = 0; k < VarLength; k++)
		{
			if (OrderMatrix[Vars[j] - 'a'][Vars[k] - 'a'] == 1 && Visited[k] == 1)
			{
				IsValid = false;
				break;
			}
		}

		if (Visited[j] == 0 && IsValid)
		{
			Result[level] = Vars[j];
			Visited[j] = 1;
			nextPermutation(level + 1);
			Visited[j] = 0;
		}
	}
}

int main()
{
	char tmpInput[1000];
	bool flag = false;

	while (fgets(tmpInput, 1000, stdin))
	{
		init(); //Init

		for (int i = 0; tmpInput[i]; i++)
		{
			if (isValidVar(tmpInput[i]))
			{
				Vars[VarLength++] = tmpInput[i];
			}
		}

		std::sort(Vars, Vars + VarLength); //Sort

		fgets(tmpInput, 1000, stdin);
		for (int i = 0; tmpInput[i]; i++)
		{
			char first, second;
			
			while (!isValidVar(tmpInput[i])) i++;
			first = tmpInput[i];
			i++;

			while (!isValidVar(tmpInput[i])) i++;
			second = tmpInput[i];
			i++;

			OrderMatrix[first - 'a'][second - 'a'] = 1; // Set order

			if (tmpInput[i] == '\0' || tmpInput[i] == '\n')
				break;
		}

		if (flag)
			printf("\n");		
		flag = true;

		//Permute
		nextPermutation(0);
	}
		
	return 0;
}