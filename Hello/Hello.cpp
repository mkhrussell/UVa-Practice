#include <iostream>
#include <string>

#include <cstdio>

using namespace std;

int main(int argc, char**argv)
{
	//freopen("../input.txt", "r", stdin);
	//string input;
	//getline(cin, input);
    
    //cout << system("pwd");

	int **adjList;
	adjList = new int *[3];
	for (int i = 0; i < 3; i++)
	{
		adjList[i] = new int[3];
	}

	adjList[0][0] = 10;
	
	cout << adjList[0][0] << endl;
}