#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

const int MAX_VARS = 30;

int TC;

char Vars[30];
int VarLength;

int Visited[MAX_VARS];
int OrderMatrix[MAX_VARS][MAX_VARS];
char Result[MAX_VARS];

bool resultExist;

void init()
{
	VarLength = 0;
	for (int i = 0; i < MAX_VARS; i++)
	{
		Vars[i] = '\0';
		//Result[i] = '\0';
		resultExist = false;
		Visited[i] = 0;
		for (int j = 0; j < MAX_VARS; j++)
		{
			OrderMatrix[i][j] = -1;
		}
	}
}

bool isValidVariable(char var)
{
	return var >= 'A' && var <= 'Z';
}

void print()
{
	for (int i = 0; i < VarLength; i++)
	{
		resultExist = true;
		printf("%c", Result[i]);
		if (i < VarLength - 1)
			printf(" ");
	}
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
			if (OrderMatrix[Vars[j] - 'A'][Vars[k] - 'A'] == 1 && Visited[k] == 1)
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

	return;
}

int main(int argc, char **argv)
{
	scanf("%d", &TC);
	bool flag = false;
	char txtLineOfText[1000];
	fgets(txtLineOfText, 1000, stdin); // Ignore next chars
	fgets(txtLineOfText, 1000, stdin); // Read blank line

	int nCase = 0;	
	while (fgets(txtLineOfText, 1000, stdin))
	{
		if (txtLineOfText[0] == '\n' || txtLineOfText[0] == '\0')
		{
			continue;
		}
		else {
			nCase++;

			init(); // Init global vars

			// Process the vars
			for (int i = 0; txtLineOfText[i]; i++)
			{
				if (isValidVariable(txtLineOfText[i]))
				{
					Vars[VarLength++] = txtLineOfText[i];
				}
			}

			// Read contraints
			fgets(txtLineOfText, 1000, stdin);
			for (int i = 0; txtLineOfText[i]; i++)
			{
				if (txtLineOfText[i] == '\0' || txtLineOfText[i] == '\n')
					break;

				char first, second;

				while (!isValidVariable(txtLineOfText[i])) i++;
				first = txtLineOfText[i];
				i++;

				while (!isValidVariable(txtLineOfText[i])) i++;
				second = txtLineOfText[i];
				i++;

				OrderMatrix[first - 'A'][second - 'A'] = 1; // Set order
			}

			if (flag)
				printf("\n");
			flag = true;

			//Permute
			nextPermutation(0);

			if (!resultExist)
			{
				printf("NO\n");
			}

			if (nCase == TC)
				break;
		}
	}

	return 0;
}