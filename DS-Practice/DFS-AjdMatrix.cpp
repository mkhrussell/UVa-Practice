#define __CRT_SECURE_NO_WARNING

#include <iostream>
#include <cstdio>

using namespace std;

#define N_LIMIT 100
#define E_LIMIT 100

#define FFOR(i, a, b) for(i=a; i < b; i++)
#define FFOR_EQ(i, a, b) for(i=a; i < b; i++)

int N, E;
int graph[N_LIMIT][N_LIMIT];

int color[N_LIMIT];
const int WHITE = 0, GRAY = 1, BLACK = 2;

void dfs_visit(int u)
{
	//cout << u + 1 << " "; // Visit starting sequence
	color[u] = GRAY;
	int v;
	FFOR(v, 0, N){
		if (graph[u][v] == 1 && color[v] == WHITE)
		{
			dfs_visit(v);
		}
	}
	//cout << u+1 << " "; // Finishing sequence
	color[u] = BLACK;
}

int dfs()
{
	int u;
	FFOR(u, 0, N){
		color[u] = WHITE;
	}

	FFOR(u, 0, N){
		if (color[u] == WHITE){
			dfs_visit(u);
		}
	}

	return 0;
}

int dfs_main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> E;
	int i, j;
	FFOR(i, 0, E){
		int u, v;
		cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}

	dfs(); //

	/*
	FFOR(i, 0, N){
		FFOR(j, 0, N){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}

/*
int main(int argc, char**argv)
{
	dfs_main();

	return 0;
}
*/
