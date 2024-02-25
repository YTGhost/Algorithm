#include <iostream>

using namespace std;

const int N = 1010;

int f[N], mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    
    f[0] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            f[j] = (f[j] + f[j-i]) % mod;
    cout << f[n] << endl;
    return 0;
}