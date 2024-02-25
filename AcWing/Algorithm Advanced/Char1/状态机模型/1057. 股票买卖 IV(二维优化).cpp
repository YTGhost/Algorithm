#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 110;
int a[N], f[M][2];

int main()
{
    int n, k;
    cin >> n >> k;
    memset(f, -0x3f, sizeof f);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    f[0][0] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = k; j >= 1; j--)
        {
            f[j][0] = max(f[j][0], f[j][1] + a[i]);
            f[j][1] = max(f[j][1], f[j-1][0] - a[i]);
        }
    int res = 0;
    for(int i = 0; i <= k; i++) res = max(res, f[i][0]);
    cout << res << endl;
    return 0;
}