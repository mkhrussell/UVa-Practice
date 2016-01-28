#include <iostream>
#include <stack>

#include <cstdio>

using namespace std;

#define N_MAX 101

int N, M;
int adjList[N_MAX][N_MAX];
int adjCount[N_MAX];
int visited[N_MAX];

stack <int> topoSortedNodes;

void dfs(int start)
{
    stack <int> stk;
    stk.push(start);
    while(!stk.empty())
    {
        int top = stk.top();
        cout << top << " ";
        stk.pop();
        visited[top] = 1;        
        for(int j = 1; j <= adjCount[top]; j++)
        {
            if(visited[j] == 0)
                stk.push(j);            
        }

		topoSortedNodes.push(top);
    }
    cout << endl;
}

void init()
{
    for(int i = 0; i < N_MAX; i++)
    {
        adjCount[i] = 0;
        visited[i] = 0;
        for(int j = 0; j < N_MAX; j++)
        {
            adjList[i][j] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    freopen("input.txt", "r", stdin);
    
    //cout << "Hello World" << endl;
    while(true)
    {
        init(); //
        
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;
        
        for(int m = 0; m < M; m++)
        {
            int i, j;
            cin >> i >> j;
            adjList[i][++adjCount[i]] = j;
        }
        
        for(int i = 1; i <= N; i++)
        {
            if(visited[i] == 0)
                dfs(i);
        }

		cout << endl << endl;
		while (!topoSortedNodes.empty())
		{
			int top = topoSortedNodes.top();
			cout << top << " ";
			topoSortedNodes.pop();
		}

    }
    
    return 0;
}
