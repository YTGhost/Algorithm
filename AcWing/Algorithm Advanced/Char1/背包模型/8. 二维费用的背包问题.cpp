#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int f[N][N], n, V, M;

int main()
{
    cin >> n >> V >> M;
    for(int i = 1; i <= n; i++)
    {
        int v, m, w;
        cin >> v >> m >> w;
        for(int j = V; j >= v; j--)
            for(int k = M; k >= m; k--)
                f[j][k] = max(f[j][k], f[j-v][k-m] + w);
    }
    cout << f[V][M] << endl;
    return 0;
}