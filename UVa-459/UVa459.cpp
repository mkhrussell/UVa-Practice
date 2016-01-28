#include <iostream>

#include <cstdio>

using namespace std;

#define N_LIMIT 100
#define E_LIMIT 100

#define FFOR(i, a, b) for(i = a; i < b; i++)
#define FFOR_EQ(i, a, b) for(i = a; i <= b; i++)

#define __INT(ch)	((int)ch - 65)
#define __CHAR(num)	((char)(num + 65))

int N, E;
int graph[N_LIMIT][N_LIMIT];

int color[N_LIMIT];
const int WHITE = 0, GRAY = 1, BLACK = 2;

int subgraphCount; // Subgraph count

void init_case()
{
	subgraphCount = 0; //Initialize the subgraph count

	int u, v;
	FFOR_EQ(u, 0, N)
	{
		FFOR_EQ(v, 0, N)
		{
			graph[u][v] = 0; //Initialize the graph
		}
	}
}

void dfs_visit(int u)
{
	color[u] = GRAY;
	int v;
	FFOR_EQ(v, 0, N) {
		if (graph[u][v] == 1 && color[v] == WHITE)
		{
			dfs_visit(v);
		}
	}
	color[u] = BLACK;
}

void dfs()
{
	int u;
	FFOR_EQ(u, 0, N)
	{
		color[u] = WHITE;
	}

	FFOR_EQ(u, 0, N) {
		if (color[u] == WHITE)
		{
			dfs_visit(u);
			subgraphCount++; // Increase subgraph count after each call
		}
	}
}

int main(int argc, char**argv)
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	cin.ignore(100, '\n');
	getchar();
	
	for (int nCase = 1; nCase <= T; nCase++)
	{
		init_case(); //

		char ch_N;
		ch_N = getchar(); getchar();
		//cout << "#" << nCase << " " << ch_N << endl;		
		N = E = __INT(ch_N); // N and E are equal here
		//cout << "N: " << N << " E: " << E << endl;

		while (true)
		{
			char ch_u;
			ch_u = getchar();
			if (ch_u == EOF || ch_u == '\n') {
				break; //End of input or end of case
			}

			char ch_v;
			ch_v = getchar(); getchar(); // Read v and ignore next
			graph[__INT(ch_u)][__INT(ch_v)] = 1; //Connect u -> v
			graph[__INT(ch_v)][__INT(ch_u)] = 1; //Connect v -> u

			graph[__INT(ch_u)][__INT(ch_u)] = 1; //Connect node itself
			graph[__INT(ch_v)][__INT(ch_v)] = 1; //Connect node itself
		}

		/* //Print the case to veryfy the input is correct or not
		cout << "case #" << nCase << ":" << endl;
		cout << __CHAR(N) << endl;

		int i, j;
		FFOR_EQ(i, 0, N) {
			FFOR_EQ(j, 0, N) {
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		dfs(); // Call DFS to graph

		if (nCase == 1) {
			cout << subgraphCount << endl;
		}
		else{
			cout << endl << subgraphCount << endl;
		}
	}

	return 0;
}