#include <iostream>

#include <string>
#include <map>
#include <stack>

#include <cstdio>

using namespace std;

#define N_LIMIT 102
#define E_LIMIT 10004

int graph[N_LIMIT][N_LIMIT];

const int DFS_WHITE = 0, DFS_GRAY = 1, DFS_BLACK = 2;
int visited[N_LIMIT];
int dfs_num[N_LIMIT];
int dfs_low[N_LIMIT];

int dfsNumberCounter = 0;
int numCC = 0;
stack<int> S;

int N, M;
int nCase;

map<string, int> nameNumMap;
map<int, string> numNameMap;

int counter = 1;

void initCase()
{
    nameNumMap.clear();
    counter = 1;
    
    dfsNumberCounter = 0;
    numCC = 0;
    
    for(int i = 0; i < N; i++)
    {
        visited[i] = DFS_WHITE;
        for(int j = 0; j < N; j++)
        {
            graph[i][j] = 0;
        }
    }
    
}

void dfs_tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push(u);
    visited[u] = DFS_BLACK;
    for(int v = 0; v < N; v++)
    {
        if(graph[u][v] && visited[v] == DFS_WHITE)
        {
            dfs_tarjan(v);
        }
        
        if(visited[v] == DFS_BLACK)
        {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    
    if(dfs_low[u] == dfs_num[u])
    {
        cout << "SCC: " << ++numCC << endl;
        bool started = false;
        while(true)
        {
            int v = S.top();
            S.pop();
            visited[v] = DFS_WHITE;
            if(!started)
            {
                cout << numNameMap[v + 1];
                started = true;
            }else {
                cout << ", " << numNameMap[v + 1];
            }
            
            if(u == v)
            {
                started = false;
                cout << endl;
                break;
            }            
        }        
        cout << endl;
    }
}

void dfs_tarjan_main()
{
    for(int i = 0; i < N; i++)
    {
        if(dfs_num[i] <= 0)
        {
            dfs_tarjan(i);
        }
    }    
}

int main(int argc, char **argv)
{
    freopen("../sample-input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    
    for(nCase = 1; (cin >> N >> M) && (N > 0 && M > 0); nCase++)   
    {
        // Reset case vars
        initCase();
        
        for(int i = 0; i < M; i++)
        {
            string name_u, name_v;
            cin >> name_u >> name_v;
            
            if(!nameNumMap[name_u])
            {
                nameNumMap[name_u] = counter;
                numNameMap[counter] = name_u;
                counter++;
            }
            
            if(!nameNumMap[name_v])
            {
                nameNumMap[name_v] = counter;
                numNameMap[counter] = name_v;
                counter++;
            }
            
            int u = nameNumMap[name_u];
            int v = nameNumMap[name_v];
            
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
        }
        
/*        //cout << "Case #" << nCase << ":" << endl;  
        cout << N << " " << M << endl;
        for (std::map<string, int>::iterator it=nameNumMap.begin(); it!=nameNumMap.end(); ++it)
        {
            cout << it->first << " => " << it->second << endl;
        }
        cout << "//" << endl;
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << graph[i][j];
            }
            cout << endl;
        }*/
        
        cout << "Calling circles for data set " << nCase << ":" << endl;
        dfs_tarjan_main();
        //cout << "//" << endl;
    } // Case read loop end

    return 0;
}
