#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 110;
int a[N], f[N][M][2];

int main()
{
    int n, k;
    cin >> n >> k;
    memset(f, -0x3f, sizeof f);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    for(int i = 0; i <= n; i++)
        f[i][0][0] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
        {
            f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1] + a[i]);
            f[i][j][1] = max(f[i-1][j][1], f[i-1][j-1][0] - a[i]);
        }
    int res = 0;
    for(int i = 0; i <= k; i++) res = max(res, f[n][i][0]);
    cout << res << endl;
    return 0;
}