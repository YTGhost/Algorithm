#include <iostream>

using namespace std;

const int N = 1010;

int f[N][N], mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i <= n; i++) f[i][0] = 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = f[i-1][j] % mod;
            if(j >= i) f[i][j] = (f[i][j] + f[i][j-i]) % mod;
        }
    cout << f[n][n] << endl;
    return 0;
}