#include <iostream>

using namespace std;

const int N = 110;

int f[N], v[N][N], w[N][N], s[N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++)
        {
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 0; j--)
            for(int k = 1; k <= s[i]; k++)
                if(j >= v[i][k]) f[j] = max(f[j], f[j-v[i][k]] + w[i][k]);
    cout << f[m] << endl;
    return 0;
}