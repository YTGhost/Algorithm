#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;

int f[N][N], v[N][N], w[N][N], g[N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> w[i][j];
        
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i-1][j-k] + w[i][k]);
    cout << f[n][m] << endl;
    
    int j = m;
    for(int i = n; i >= 1; i--)
    {
        for(int k = 0; k <= j; k++)
            if(f[i][j] == f[i-1][j-k] + w[i][k])
            {
                cout << i << " " << k << endl;
                j -= k;
                break;
            }
    }
    return 0;
}