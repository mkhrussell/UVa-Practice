#include <iostream>
#include <cstdio>

#define INT32_MIN		(-2147483647-1)

using namespace std;

int findMaxCycle(int i, int j)
{
	if(i > j)
	{
		int c = j;
		j = i;
		i = c;
	}
	
	int nMaxCycle = INT32_MIN;
	int nCycle = 1;
	for(int k = i; k <= j; k++)
	{
		int n = k;
		while(n != 1)
		{
			if(n%2 == 0)
				n = n/2;
			else
				n = 3*n + 1;
			++nCycle;
		}
		
		if(nCycle > nMaxCycle)
			nMaxCycle = nCycle;
		
		nCycle = 1;
	}
	
	return nMaxCycle;
}

int main(int argc, char **argv)
{
	//freopen("../res/input02.txt", "r", stdin);
    int i, j;
	while(scanf("%d %d", &i, &j) != EOF)
	{
		int result = findMaxCycle(i, j);
		printf("%d %d %d\n", i, j, result);		
	}
    return 0;
}
