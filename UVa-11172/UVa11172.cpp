#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int T, a, b;
    
    cin >> T; //Read the number of cases
    for(int t = 0; t < T; ++t)
    {
        cin >> a >> b;
        if(a < b)
            cout << "<" << endl;
        else if(a > b)
            cout << ">" << endl;
        else if(a == b)
            cout << "=" << endl;
    }
    
    return 0;
}
