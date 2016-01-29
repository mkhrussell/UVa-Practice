#include <iostream>

//#include <cstdio>

using namespace std;

#define N_LIMIT 100

const int WHITE = 0, GRAY = 1, BLACK = 2;

int graph[N_LIMIT][N_LIMIT];
char graph_out[N_LIMIT][N_LIMIT]; // Output formating graph
int reached[N_LIMIT];

int reachable_dfs_zero[N_LIMIT]; // generate spanning tree

int N;
int deleted = -1;

int T;
int nCase;

void init_case()
{
    for(int i = 0; i < N_LIMIT; i++)
    {
        reached[i] = WHITE;
        reachable_dfs_zero[i] = WHITE;
        deleted = -1;
        
        for(int j = 0; j < N_LIMIT; j++)
        {
            graph[i][j] = 0;
            graph_out[i][j] = '\0';
        }
    }
}

void init_reached()
{
    for(int i = 0; i < N_LIMIT; i++)
    {
        reached[i] = WHITE;
    }
}

void dfs_visit(int u_root)
{
    if(u_root == deleted) // deleted node, so no need to process
        return;
    
    reached[u_root] = GRAY;
    for(int v = 0; v < N; v++)
    {
        if(graph[u_root][v] == 1 && reached[v] == WHITE)
            dfs_visit(v);
    }    
    reached[u_root] = BLACK;
}


int main(int argc, char **argv)
{
    //freopen("../sample-input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    
    cin >> T;
    for(int nCase = 1; nCase <= T; nCase++)
    {
        cin >> N;
        
        init_case(); //Init the case variables
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }
        
        // Run dfs(0) first: This is special case
        init_reached();
        dfs_visit(0);        
        for(int i = 0; i < N; i++){
            reachable_dfs_zero[i] = reached[i];
            if(reached[i] == BLACK) // check for visited from 0. visited means dominated
                graph_out[0][i] = 'Y';
            else
                graph_out[0][i] = 'N';
        }
        // End of special case
        
        // Solve
        for(int u = 1; u < N; u++) // Call dfs for 1 to N-1
        {
            init_reached();
            
            deleted = u; // hide from dfs call
            //reached[u] = BLACK; // temporary stop visiting connected nodes
            
            dfs_visit(0); // Always call DFS from '0'
            
            if(reachable_dfs_zero[u] == BLACK) // Reachable by dfs(0)
            {
                for(int v = 0; v < N; v++)
                {                
                    if(reached[v] == WHITE) // check for unvisited. unvisited means not reachable or not dominated
                        graph_out[u][v] = 'Y';
                    else
                        graph_out[u][v] = 'N';
                    
                    if(reachable_dfs_zero[v] == WHITE) // Special Condition: not reachable by dfs(0)
                        graph_out[u][v] = 'N';
                }                
                graph_out[u][u] = 'Y'; // self is dominated
            }else{
                for(int v = 0; v < N; v++)
                {                
                    graph_out[u][v] = 'N';
                }                
            }

        }
        
        
        // Print
        cout << "Case " << nCase << ":" << endl;
        for(int i = 0; i < N; i++)
        {
            cout << "+";
            for(int n = 0; n < N * 2 - 1; n++)
                cout << "-";
            cout << "+" << endl << "|";    
                
            for(int j = 0; j < N; j++)
            {
                cout << graph_out[i][j] << "|";
            }
            cout << endl;              
        }
        cout << "+";
            for(int n = 0; n < N * 2 - 1; n++)
                cout << "-";
            cout << "+" << endl;
    }
    
    
    return 0;
}
