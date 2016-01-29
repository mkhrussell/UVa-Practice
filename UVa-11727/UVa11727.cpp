#include <iostream>
#include <list>

//#include <cstdio>

using namespace std;

list <int> salaries;
int T;

int main(int argc, char **argv)
{
	//freopen("../sample-input.txt", "r", stdin);
	//freopen("../output.txt", "w", stdout);

	cin >> T;
	for (int nCase = 1; nCase <= T; nCase++)
	{
		salaries.clear();
		int a, b, c;
		cin >> a >> b >> c;

		salaries.push_back(a);
		salaries.push_back(b);
		salaries.push_back(c);

		salaries.sort();
		salaries.pop_front();

		cout << "Case " << nCase << ": " << salaries.front() << endl;
	}

	return 0;
}