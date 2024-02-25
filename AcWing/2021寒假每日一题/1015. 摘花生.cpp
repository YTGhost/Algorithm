#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;

int f[N], a[N][N];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> a[i][j];
        
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                f[j] = max(f[j], f[j-1]) + a[i][j];
        cout << f[m] << endl;
        memset(f, 0, sizeof f);
    }
    return 0;
}