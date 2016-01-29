#include <iostream>
#include <cstdio>

using namespace std;

#define N_MAX 102
#define S_MAX 10000

char theArena[N_MAX][N_MAX];
char instructionList[S_MAX];

int N, M, S;

char direction;
int x, y;
int starCount = 0;

void init()
{
	for (int i = 0; i < N_MAX; i++)
	for (int j = 0; j < N_MAX; j++)
	{
		theArena[i][j] = '0';
	}

	for (int s = 0; s < S_MAX; s++)
	{
		instructionList[s] = '0';
	}

	starCount = 0;
}

void readCase()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> theArena[i][j];
		}
	}

	for (int k = 0; k < S; k++)
	{
		cin >> instructionList[k];
	}
}

void goToStart()
{
	bool reachedAtStart = false;
	for (int i = 1; i <= N && !reachedAtStart; i++)
	{
		for (int j = 1; j <= M && !reachedAtStart; j++)
		{
			if (theArena[i][j] == 'N' || theArena[i][j] == 'S' || theArena[i][j] == 'L' || theArena[i][j] == 'O'){
				direction = theArena[i][j];
				x = i;
				y = j;
				reachedAtStart = true;				
			}
		}		
	}
}

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// "D" >> "turn 90 degrees to the right"
	// "E" >> "turn 90 degrees to the left"
	// "F" >> "move forward one cell"

	while (true)
	{
		cin >> N >> M >> S;
		if (N == 0) break; // means end of input

		init(); //initialize to '0'
		readCase(); //
		goToStart(); // Determine robot's position

		for (int s = 0; s < S; s++)
		{
			if (instructionList[s] == 'D')
			{
				if (direction == 'N')
					direction = 'L';
				else if (direction == 'L')
					direction = 'S';
				else if (direction == 'S')
					direction = 'O';
				else if (direction == 'O')
					direction = 'N';
				
			}
			else if (instructionList[s] == 'E')
			{
				if (direction == 'N')
					direction = 'O';
				else if (direction == 'O')
					direction = 'S';
				else if (direction == 'S')
					direction = 'L';
				else if (direction == 'L')
					direction = 'N';
			}
			else if (instructionList[s] == 'F')
			{
				if (direction == 'N' && theArena[x - 1][y] != '#' && theArena[x - 1][y] != '0')
				{
					x--;						
				}
				else if (direction == 'L' && theArena[x][y + 1] != '#' && theArena[x][y + 1] != '0')
				{
					y++;
				}
				else if (direction == 'S' && theArena[x + 1][y] != '#' && theArena[x + 1][y] != '0')
				{
					x++;
				}
				else if (direction == 'O' && theArena[x][y - 1] != '#' && theArena[x][y - 1] != '0')
				{
					y--;
				}
				else{
					continue;
				}

				if (theArena[x][y] == '*')
				{
					starCount++;
					theArena[x][y] = '.';
				}
			}
		}

		cout << starCount << endl;
	}


	return 0;
}