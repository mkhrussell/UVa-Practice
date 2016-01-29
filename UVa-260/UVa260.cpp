#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N;
char G[205][205];
bool V[205][205];

int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 0, -1, 1, 0, 1};

char output = 'W';

void dfs(int x, int y) // Recursively search path exist for B; otherwise it will be W.
{
    V[x][y] = true;
    if(x == N-1)
    {
        output = 'B';
        return;
    }
    
    for(int i = 0; i < 6; i++)
    {
        int r = x + dr[i];       ;
        int c = y + dc[i];
        if(r >= 0 && r < N && c >= 0 && c < N && !V[r][c])
        {
            if(G[r][c] == 'b')
                dfs(r,c);
        }
    }    
}

int main(int argc, char **argv)
{
    //freopen("../res/input02.txt", "r", stdin);
    
    for(int nCase = 1; cin >> N && N; nCase++)
    {
        for(int r = 0; r < N; r++)
        {
            cin >> G[r];
        }
        
        for(int c = 0; c < N; c++)
        {
            if(G[0][c] == 'b')
                dfs(0, c);
        }
        
        cout << nCase << " " << output << endl;
        
        output = 'W';
        memset(G, '\0', sizeof(G));
        memset(V, false, sizeof(V));
    }    
    
    return 0;
}
