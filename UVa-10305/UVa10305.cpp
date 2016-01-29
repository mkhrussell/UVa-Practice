#include <iostream>
#include <stack>

//#include <cstdio>

#define N_MAX 1001

using namespace std;

int G[N_MAX][N_MAX];
int conCount[N_MAX];
int visited[N_MAX];

stack <int> visitOrder;

int N, M;

void init()
{
	for (int i = 0; i < N_MAX; i++)
	{
		conCount[i] = 0;
		visited[i] = 0;

		for (int j = 0; j < N_MAX; j++)
		{
			G[i][j] = 0;
		}
	}
}

void dfs(int start)
{
	stack <int> nodes;
	int currentNode = start;

	visited[currentNode] = 1;
	nodes.push(currentNode);
	while (!nodes.empty())
	{
		currentNode = nodes.top();		
		visited[currentNode] = 1;
				
		for (int j = 1; j <= conCount[currentNode]; j++)
		{
			int conNode = G[currentNode][j];
			
			if (visited[conNode] != 1)
			{
				nodes.push(conNode);				
			}
		}
				
		if (nodes.top() == currentNode){
			visitOrder.push(currentNode); // order of visit // topological sort will be reverse order of visit
			nodes.pop();
		}		
	}
}

int main(int argc, char **argv)
{
	//freopen("../sample-input.txt", "r", stdin);
	//freopen("../output.txt", "w", stdout);

	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		
		init(); //

		for (int m = 0; m < M; m++)
		{
			int i, j;
			cin >> i >> j;
			G[i][++conCount[i]] = j;
		}

		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0)
				dfs(i);
		}

		//Reverse the order of visit and print: output is topological order
		while (!visitOrder.empty())
		{
			cout << visitOrder.top() << " ";
			visitOrder.pop();
		}

		cout << endl;
	}
	
	return 0;
}
