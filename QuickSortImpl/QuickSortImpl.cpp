#include <iostream>
#include <cstdio>

using namespace std;

class Quick {
public:
	static void sort(int A[], int lo, int hi);
private:
	Quick() {}
	~Quick() {}
	static int doPartition(int A[], int lo, int hi);

	static bool isLessThen(int a, int b)
	{
		return (a - b) < 0;
	}

	static void swapValue(int A[], int x, int y)
	{
		int val_x = A[x];
		A[x] = A[y];
		A[y] = val_x;
	}
};

int Quick::doPartition(int A[], int lo, int hi)
{
	int i = lo;
	int j = hi + 1;
	int v = A[lo];

	while (true)
	{
		while (isLessThen(A[++i], v))
		{
			if (i == hi)
				break;
		}

		while (isLessThen(v, A[--j]))
		{
			if (j == lo)
				break;
		}

		if (i >= j)
			break;

		swapValue(A, i, j);
	}

	swapValue(A, lo, j);

	return j;
}

void Quick::sort(int A[], int lo, int hi)
{
	if (hi <= lo)
		return;
	int j = doPartition(A, lo, hi);
	sort(A, lo, j - 1);
	sort(A, j + 1, hi);
}

int main(int argc, char **argv)
{
	freopen("unsorted-integer-input.txt", "r", stdin);
	freopen("sorted-integer-ouput.txt", "w", stdout);

	int myIntArray[200];

	int N = 0;
	int num;
	cout << "Input array: " << endl;
	while (scanf("%d", &num) != EOF)
	{
		myIntArray[N] = num;
		N++;
		cout << num << endl;
	}
	cout << "//" << endl << endl;
	
	cout << "Sorted array: " << endl;
	Quick::sort(myIntArray, 0, N - 1); // Run quicksort
	for (int i = 0; i < N; i++)
	{
		cout << myIntArray[i] << endl;
	}
	cout << "//" << endl;

	return 0;
}