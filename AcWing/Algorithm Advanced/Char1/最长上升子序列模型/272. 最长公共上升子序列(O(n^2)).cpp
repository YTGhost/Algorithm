#include <iostream>

using namespace std;

const int N = 3010;

int f[N][N], a[N], b[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    
    for(int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = f[i-1][j];
            if(a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if(b[j] < a[i]) maxv = max(maxv, f[i-1][j] + 1);
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, f[n][i]);
    cout << res << endl;
    return 0;
}