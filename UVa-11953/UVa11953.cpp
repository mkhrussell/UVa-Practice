#include <iostream>

//#include <cstdio>

using namespace std;

#define N_MAX 102

char theGrid[N_MAX][N_MAX];
int T;
int N;
int validShipCount = 0;

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		for (int j = 0; j < N_MAX; j++)
		{
			theGrid[i][j] = '0';
		}
	}

	validShipCount = 0;
}

void readCase()
{
	cin >> N;
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			cin >> theGrid[x][y];
		}
	}
}

bool isShipAlive(int r, int c)
{
	bool xFound = false;
	if (theGrid[r][c] == 'x')
	{
		xFound = true;
		theGrid[r][c] = 'v';
	}
	else if (theGrid[r][c] == '@')
	{
		theGrid[r][c] = 'v';
	}

	int up = r - 1, down = r + 1, left = c - 1, right = c + 1;
	while (up > 0)
	{
		if (theGrid[up][c] == 'x')
		{
			xFound = true;
			theGrid[up][c] = 'v';
		}
		else if (theGrid[up][c] == '@')
		{
			theGrid[up][c] = 'v';
		}
		else if (theGrid[up][c] == '.')
		{
			break;
		}

		up--;
	}

	while (down <= N)
	{
		if (theGrid[down][c] == 'x')
		{
			xFound = true;
			theGrid[down][c] = 'v';
		}
		else if (theGrid[down][c] == '@')
		{
			theGrid[down][c] = 'v';
		}
		else if (theGrid[down][c] == '.')
		{
			break;
		}

		down++;
	}

	//////
	while (left > 0)
	{
		if (theGrid[r][left] == 'x')
		{
			xFound = true;
			theGrid[r][left] = 'v';
		}
		else if (theGrid[r][left] == '@')
		{
			theGrid[r][left] = 'v';
		}
		else if (theGrid[r][left] == '.')
		{
			break;
		}

		left--;
	}

	while (right <= N)
	{
		if (theGrid[r][right] == 'x')
		{
			xFound = true;
			theGrid[r][right] = 'v';
		}
		else if (theGrid[r][right] == '@')
		{
			theGrid[r][right] = 'v';
		}
		else if (theGrid[r][right] == '.')
		{
			break;
		}

		right++;
	}


	return xFound;
}

int main(int argc, char **argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> T;
	for (int nCase = 1; nCase <= T; nCase++)
	{
		init(); //
		readCase();
		for (int x = 1; x <= N; x++)
		{
			for (int y = 1; y <= N; y++)
			{
				if (theGrid[x][y] == '@' && isShipAlive(x, y))
				{
					validShipCount++;
				}
				else if (theGrid[x][y] == 'x' && isShipAlive(x, y))
				{
					validShipCount++;
				}
				else if (theGrid[x][y] == '.')
				{
					continue;
				}
			}
		}
		cout << "Case " << nCase << ": " << validShipCount << endl;
	}	

	return 0;
}