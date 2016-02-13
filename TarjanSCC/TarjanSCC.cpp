#include <iostream>

#include <string>
#include <map>
#include <stack>

#include <cstdio>

using namespace std;

int m_min(int a, int b)
{
	return a < b ? a : b;
}

#define N_LIMIT 102
#define E_LIMIT 10004

int graph[N_LIMIT][N_LIMIT];

const int DFS_UNVISITED = -1, DFS_VISITED = 1;
int dfs_visited[N_LIMIT];
int dfs_num[N_LIMIT];
int dfs_low[N_LIMIT];

int dfsNumberCounter = 0;
int numCC = 0;

int N, M;
int nCase;

stack<int> stk_visitOrder;

void resetCase()
{
	for (int i = 0; i < N; i++)
	{
		dfs_visited[i] = 0;
		dfs_num[i] = DFS_UNVISITED;
		dfs_low[i] = DFS_UNVISITED;

		for (int j = 0; j < N; j++)
		{
			graph[i][j] = 0;
		}
	}
}

void dfs_tarjanSCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	stk_visitOrder.push(u);
	dfs_visited[u] = 1;

	for (int v = 0; v < N; v++) {
		if (graph[u][v] == 1)
		{
			if (dfs_num[v] == DFS_UNVISITED)
			{
				dfs_tarjanSCC(v);
			}

			if (dfs_visited[v])
			{
				dfs_low[u] = m_min(dfs_low[u], dfs_low[v]);
			}
		}
	} // Recursion ended

	if (dfs_low[u] == dfs_num[u])
	{
		cout << "SCC " << ++numCC << ": ";
		while (true)
		{
			int v = stk_visitOrder.top(); stk_visitOrder.pop();
			dfs_visited[v] = 0;
			cout << v << " ";
			if (u == v) break;
		}
		cout << endl;
	}
}

void dfs_tarjan()
{
	dfsNumberCounter = 0;
	numCC = 0;

	for (int u = 0; u < N; u++)
	{
		if (dfs_num[u] == DFS_UNVISITED)
		{
			dfs_tarjanSCC(u);
		}
	}
}

int main(int argc, char **argv)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	for (nCase = 1; cin >> N >> M && N > 0 && M > 0; nCase++)
	{
		resetCase(); // Reset previous graph and case-specific variables

		cout << "Case #" << nCase << ":" << endl;
		cout << "N: " << N << " M: " << M << endl;
		for (int m = 0; m < M; m++)
		{
			int u, v;
			cin >> u >> v;
			graph[u][v] = 1;
			cout << u << " --> " << v << endl;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << graph[i][j] << " ";
			}
			cout << endl;
		}
		cout << "//" << endl;

		dfs_tarjan(); // Call Tarjan
	}

	return 0;
}
