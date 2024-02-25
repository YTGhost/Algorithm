#include <iostream>

using namespace std;

const int N = 110, INF = 1e9;

int f[N], w[N][N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> w[i][j];
            
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(i == 1) f[j] = INF;  // 上边界
            if(j == 1) f[j-1] = INF;    // 左边界
            if(i == 1 && j == 1) f[j] = w[i][j];
            else f[j] = min(f[j], f[j-1]) + w[i][j];
        }
            
    cout << f[n] << endl;
    return 0;
}