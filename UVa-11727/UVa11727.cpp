#include <iostream>

using namespace std;

int T;
int numCase;

int main(int argc, char **argv)
{
    //freopen("F:\\Programming\\UVA-Practice\\UVa-11727\\input.txt", "r", stdin);

    cin >> T;
    for (numCase = 1; numCase <= T; numCase++)
    {
        int salOne, salTwo, salThree, salSurv;
        cin >> salOne >> salTwo >> salThree;

        if (salOne >= salTwo)
            salSurv = salOne;
        else
            salSurv = salTwo;

        if (salSurv > salThree)
            salSurv = salThree;
        

        cout << "Case " << numCase << ": " << salSurv << endl;
    }

    return 0;
}