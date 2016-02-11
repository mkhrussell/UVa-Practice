#define __CRT_SECURE_NO_WARNING

#include <iostream>
#include <cstdio>

using namespace std;

#define N_LIMIT 100
#define M_INFINITY 100000

#define FFOR(i, a, b) for(i=a; i < b; i++)
#define FFOR_EQ(i, a, b) for(i=a; i < b; i++)

int N;
int graph[N_LIMIT][N_LIMIT];
int key_val[N_LIMIT];
int mst_status[N_LIMIT];
int mst_parent[N_LIMIT];
int mst_cost = 0;

const int WHITE = 0, BLACK = 1;

int findMin()
{
    int minVal = M_INFINITY;
    int minVert = 0;
    int i;
    FFOR(i, 0, N)
    {
        if (mst_status[i] == WHITE)
        {
            if (minVal > key_val[i])
            {
                minVal = key_val[i];
                minVert = i;
            }
        }
    }

    return minVert;
}

int prims(int source)
{
    int i;
    FFOR(i, 0, N_LIMIT)
    {
        key_val[i] = M_INFINITY;
        mst_status[i] = WHITE;
        mst_parent[i] = -1;
    }

    key_val[source] = 0; // Source to source distance is: 0
    mst_parent[source] = -1;
    FFOR(i, 0, (N - 1))
    {
        int u = findMin();
        mst_status[u] = BLACK;
        int v;
        FFOR(v, 0, N)
        {
            if (graph[u][v] && mst_status[v] == WHITE && key_val[v] > graph[u][v])
            {
                key_val[v] = graph[u][v];
                mst_parent[v] = u;
            }
        }
    }

    return 0;
}

void print_mst()
{
    mst_cost = 0;
    int i;
    cout << "MST Edge : weight" << endl;
    FFOR(i, 1, N)
    {
        cout << mst_parent[i] << " --> " << i << " : " << graph[mst_parent[i]][i] << endl;
        mst_cost += graph[mst_parent[i]][i];
    }
    cout << "MST Cost : " << mst_cost << endl;
}

int prims_main()
{
    freopen("../input.txt", "r", stdin);
    cin >> N;
    int i, j;
    FFOR(i, 0, N)
    {
        FFOR(j, 0, N)
        {
            cin >> graph[i][j];			
        }
    }

    cout << "Input graph:" << endl;
    FFOR(i, 0, N)
    {
        FFOR(j, 0, N)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "//" << endl;

    prims(0); // Run prims

    return 0;
}


int main(int argc, char** argv)
{
    prims_main();    
    print_mst();

    return 0;
}
