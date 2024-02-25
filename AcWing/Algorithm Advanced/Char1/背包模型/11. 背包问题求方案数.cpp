#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010, mod = 1e9 + 7;

int f[N], g[N];

int main()
{
    int n, m;
    cin >> n >> m;
    g[0] = 1;
    
    for(int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        for(int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j-v] + w);
            int cnt = 0;
            if(maxv == f[j]) cnt += g[j];
            if(maxv == f[j-v] + w) cnt += g[j-v];
            f[j] = maxv;
            g[j] = cnt % mod;
        }
    }
    int res = 0;
    for(int i = 0; i <= m; i++) res = max(res, f[i]);
    int cnt = 0;
    for(int i = 0; i <= m; i++)
        if(res == f[i])
            cnt += g[i];
    cout << cnt << endl;
    return 0;
}