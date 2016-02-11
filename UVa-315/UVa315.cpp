#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define N_LIMIT 102
//#define E_LIMIT 1000000000

// DFS vars
const int DFS_UNVISIED = -1, DFS_EXPLORED = 0, DFS_VISITED = 1;
const int DFS_NIL = 0;
const int DFS_ROOT = 1;

int adjList[N_LIMIT][N_LIMIT];
int adjNodeCount[N_LIMIT];
int dfsVisited[N_LIMIT];

// Articulation vars
int dfsNum[N_LIMIT];
int dfsLow[N_LIMIT];
int dfsParent[N_LIMIT];
int articulationVertex[N_LIMIT];

int dfsNumCounter = 0;

int dfsRoot = 1;
int rootChildren = 0;

int N, E; // Number of vertices, edges

// Case vars
int T;
int nCase;

int mathMin(int a, int b)
{
	if (a < b)
		return a;
	
	return b;
}

int mathMax(int a, int b)
{
	if (a > b)
		return a;

	return b;
}

void caseInit()
{
	dfsNumCounter = 0;

	for (int i = 0; i < N_LIMIT; i++)
	{
		adjNodeCount[i] = 0; // No connected node
		for (int j = 0; j < N_LIMIT; j++)
		{
			adjList[i][j] = DFS_NIL; // put invalid vertex
		}
	}	
}

void dfsInit()
{
	dfsRoot = DFS_ROOT;
	rootChildren = 0;

	for (int u = 0; u < N_LIMIT; u++)
	{
		dfsVisited[u] = DFS_UNVISIED; // Mark as unvisited

		dfsNum[u] = dfsLow[u] = 0;
		dfsParent[u] = DFS_NIL;

		articulationVertex[u] = 0;
	}
}

void dfsVisit(int u)
{
	dfsVisited[u] = DFS_EXPLORED; // Mark as explored	
	// cout << u << " ";

	dfsNum[u] = dfsLow[u] = dfsNumCounter++;

	for (int i = 0; i < adjNodeCount[u]; i++)
	{
		int v = adjList[u][i]; // get next connected nodes of u
		if (v > DFS_NIL) // check vertex is valid or not
		{
			if (dfsVisited[v] == DFS_UNVISIED) // Unvisited normal edge
			{
				// Set parents in preorder / before DFS call
				dfsParent[v] = u;

				// Increase rootChildren
				if (u == dfsRoot) rootChildren++;

				dfsVisit(v); // Call DFS recursively for connected node of u
								
				if (dfsLow[v] >= dfsNum[u])
				{
					articulationVertex[u] = 1;
				}

				/*
				if (dfsLow[v] > dfsNum[u]) // Articulation bridge
				{
					// cout << u << "--" << v << ": is art bridge" << endl;
				} */

				// Set low in post order / after DFS call
				dfsLow[u] = mathMin(dfsLow[u], dfsLow[v]);

			}
            // dfsVisited[v] == DFS_VISIED or dfsVisited[v] == DFS_EXPLORED: How? Ans: there is a back edge.
			else if (v != dfsParent[u]) // Back edge is indirect?
			{
				dfsLow[u] = mathMin(dfsLow[u], dfsNum[v]);
			}
		}
	}

	dfsVisited[u] = DFS_VISITED; // Finally mark as visited
}

void dfsMain()
{
	dfsInit(); // Init all DFS flags and counters

	for (int u = 1; u <= N; u++) // Nodes are numbered from 1 to N
	{
		if (dfsVisited[u] == DFS_UNVISIED)
		{
			dfsRoot = u; rootChildren = 0;
			
			dfsVisit(u); // Call DFS

			if (rootChildren > 1) // Special case
			{
				articulationVertex[u] = 1;
			}
			else {
				articulationVertex[u] = 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	freopen("sample-input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (nCase = 1; scanf("%d", &N) && N > 0; nCase++)
	{
		getchar(); // discard '\n'

		caseInit(); // Init the case vars

		char input[10000]; // adjacency buffer
		while (gets(input) && strcmp(input, "0")) // Read adjacency list
		{
			char *pChars; // Temp buffer

			pChars = strtok(input, " ");
			int u = atoi(pChars);

			pChars = strtok(NULL, " ");
			while (pChars != NULL)
			{
				int v = atoi(pChars);
				// Edges are both way connected
				adjList[u][adjNodeCount[u]++] = v;
				adjList[v][adjNodeCount[v]++] = u;

				pChars = strtok(NULL, " ");
			}
		} // End case read

		// cout << "Case #" << nCase << " ";

		// Solve the Case
		dfsMain(); //

		int artPointCount = 0;
		for (int u = 1; u <= N; u++)
		{			
			if (articulationVertex[u] > 0)
				artPointCount++;
		}
		
		cout << artPointCount << endl;
	}

	return 0;
}