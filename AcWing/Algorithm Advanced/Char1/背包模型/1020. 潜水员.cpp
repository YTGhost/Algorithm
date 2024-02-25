#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
int f[30][80];

int main()
{
    int k, m, n;
    cin >> m >> n >> k;
    memset(f, INF, sizeof f);
    f[0][0] = 0;
    for(int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for(int j = m; j >= 0; j--)
            for(int k = n; k >= 0; k--)
                f[j][k] = min(f[j][k], f[max(0, j-a)][max(0, k-b)] + c);
    }
    cout << f[m][n] << endl;
    return 0;
}