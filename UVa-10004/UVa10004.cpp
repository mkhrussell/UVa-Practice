#include <iostream>
#include <queue>

//#include <cstdio>

using namespace std;

#define N_MAX 1001
#define N_INF 100000000

int adjList[N_MAX][N_MAX];
int numCC[N_MAX];
int dist[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		dist[i] = N_INF;
		numCC[i] = 0;
		for (int j = 0; j < N_MAX; j++)
		{
			adjList[i][j] = -1;
		}
	}
}

bool bfs(int start)
{
	queue <int> que;
	bool isBicolorabe = true;

	dist[start] = 0;
	que.push(start);
	while (!que.empty() && isBicolorabe)
	{
		int parent = que.front();
		que.pop();
		for (int j = 0; j < numCC[parent]; j++)
		{
			int child = adjList[parent][j];
			if(dist[child] == N_INF)
			{
				dist[child] = 1 - dist[parent]; // value will be {1 or 0}
				que.push(child);
			}else if(dist[child] == dist[parent])
			{
				isBicolorabe = false;
				break;
			}
		}
	}

	return isBicolorabe;
}

int main(int argc, char **argv)
{
	//freopen("../sample-input2.txt", "r", stdin);
	//freopen("../output.txt", "w", stdout);

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;

		int L;
		cin >> L;

		init(); //

		for (int ln = 0; ln < L; ln++)
		{
			int x, y;
			cin >> x >> y;
			adjList[x][numCC[x]++] = y;
		}

		if(bfs(0) == true)
		{
			cout << "BICOLORABLE." << endl;
		}
		else
		{
			cout << "NOT BICOLORABLE." << endl;
		}
	}

	return 0;
}