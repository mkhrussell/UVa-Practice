// Suppress some compilation warning messages (only for VC++ users)
// #define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

#define M_INFINITY 1000000000 // 1 billion
#define M_LIMIT 200004
#define N_LIMIT 200004

#define FFOR(i, a, b) for(i=a; i < b; i++)

int key_val[N_LIMIT];
int mst_status[N_LIMIT];
int mst_parent[N_LIMIT];
int mst_cost = 0;
int initial_cost = 0;

const int WHITE = 0, BLACK = 1;


//int **adjList;
//int *adjNodeCount;
int **edgeWeightMatrix;

int M, N;
int nCase;

void initCase()
{
	initial_cost = 0;
	//adjNodeCount = new int[M];
	//adjList = new int *[M];
	edgeWeightMatrix = new int *[M];
	for (int i = 0; i < M; i++)
	{
		//adjList[i] = new int[M];
		edgeWeightMatrix[i] = new int[M];
	}

	for (int i = 0; i < M; i++)
	{
		//adjNodeCount[i] = 0;
		for (int j = 0; j < M; j++)
		{
			//adjList[i][j] = -1;
			edgeWeightMatrix[i][j] = 0;
		}
	}
}

void freeMemory()
{
	for (int i = 0; i < M; i++)
	{
		//delete adjList[i];
		delete edgeWeightMatrix[i];
	}
	//delete[] adjList;
	delete[] edgeWeightMatrix;
	//delete adjNodeCount;
}

int findMin()
{
	int minVal = M_INFINITY;
	int minVert = 0;
	int i;
	FFOR(i, 0, M)
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
	FFOR(i, 0, M)
	{
		key_val[i] = M_INFINITY;
		mst_status[i] = WHITE;
		mst_parent[i] = -1;
	}

	key_val[source] = 0; // Source to source distance is: 0
	mst_parent[source] = -1;
	mst_cost = 0;
	FFOR(i, 0, (M - 1))
	{
		int u = findMin();
		mst_status[u] = BLACK;
		int v;
		FFOR(v, 0, M)
		{
			if (edgeWeightMatrix[u][v] && mst_status[v] == WHITE && key_val[v] > edgeWeightMatrix[u][v])
			{
				key_val[v] = edgeWeightMatrix[u][v];
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
	//cout << "MST Edge : weight" << endl;
	FFOR(i, 1, M)
	{
		// cout << mst_parent[i] << " --> " << i << " : " << edgeWeightMatrix[mst_parent[i]][i] << endl;
		mst_cost += edgeWeightMatrix[mst_parent[i]][i];
	}
	//cout << "Initial Cost: " << initial_cost << endl;
	//cout << "MST Cost : " << mst_cost << endl;
	//cout << "Savings: " << (initial_cost - mst_cost) << endl;
	cout << (initial_cost - mst_cost) << endl;
}

int main(int argc, char **argv)
{
	//freopen("sample-input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (nCase = 1; (cin >> M >> N) && (M > 0 && N > 0); nCase++)
	{
		initCase(); // Init case vars
		for (int n = 0; n < N; n++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			// Edges are both way connected
			//adjList[x][adjNodeCount[x]++] = y;
			//adjList[y][adjNodeCount[y]++] = x;

			initial_cost += z;
			// Weight of the edges
			edgeWeightMatrix[x][y] = z;
			edgeWeightMatrix[y][x] = z;
		}

		//// Print
		//cout << "Case #" << nCase << ": adj list" << endl;		
		//for (int i = 0; i < M; i++)
		//{
		//	cout << i << ": ";
		//	for (int j = 0; j < adjNodeCount[i]; j++)
		//	{
		//		cout << adjList[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << "Weighted Matrix:" << endl;
		//int i, j;
		//FFOR(i, 0, M)
		//{
		//	FFOR(j, 0, M)
		//	{
		//		cout << edgeWeightMatrix[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << "//" << endl;

		prims(0); // Run prims		
		print_mst();

		freeMemory(); // free memory
	}

	return 0;
}