#include <iostream>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int f[N][N], a[N][N];

int main()
{
    int n, res;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
            
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= i+1; j++)
            f[i][j] = -INF;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
            
    res = f[n][1];
    for(int i = 2; i <= n; i++)
        res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}
