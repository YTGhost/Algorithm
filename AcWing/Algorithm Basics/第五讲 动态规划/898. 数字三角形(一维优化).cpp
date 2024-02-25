#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;

int f[N], a[N][N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
            
    for(int j = 0; j <= 2; j++)
        f[j] = -INF;
    
    f[1] = a[1][1];
    
    for(int i = 2; i <= n; i++)
    {
        f[0] = -INF;
        f[i+1] = -INF;
        for(int j = i; j >= 1; j--)
            f[j] = max(f[j-1], f[j]) + a[i][j];
    }
        
    int res = -INF;
    for(int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}