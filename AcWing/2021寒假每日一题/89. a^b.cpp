#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b, p, res = 1;
    cin >> a >> b >> p;
    while(b)
    {
        if(b&1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    cout << res % p << endl;
    return 0;
}