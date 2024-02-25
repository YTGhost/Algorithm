#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int p = 0, pa = 0, pat = 0;
    for(auto c : str)
    {
        if(c == 'P') p++;
        else if(c == 'A') pa += p;
        else if(c == 'T') pat = (pat + pa) % 1000000007;
    }
    cout << pat << endl;
    return 0;
}