#include <iostream>

using namespace std;

const int N = 1010;

int f[N][N], mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    
    f[0][0] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % mod;
    int res = 0;
    for(int i = 1; i <= n; i++) res = (res + f[n][i]) % mod;
    cout << res << endl;
    return 0;
}