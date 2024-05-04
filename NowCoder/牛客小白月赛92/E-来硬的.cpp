#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> times(n + 1);
    vector<int> volumes(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> volumes[i] >> times[i];
    }
    vector<vector<vector<ll>>> f(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2, INT_MAX)));
    for(int i = 0; i <= n; i++) {
        f[i][0][0] = 0;
        f[i][0][1] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            f[i][j][0] = f[i - 1][j][0];
            f[i][j][1] = f[i - 1][j][1];
            f[i][j][0] = min(f[i][j][0], f[i - 1][max(j - volumes[i], 0)][0] + times[i]);
            f[i][j][1] = min(f[i][j][1], f[i - 1][max(j - volumes[i], 0)][1] + times[i]);
            f[i][j][1] = min(f[i][j][1], f[i - 1][max(j - 2 * volumes[i], 0)][0] + times[i] / 2);
        }
    }
    // 会超时
    // for(int i = 1; i <= n; i++) {
    //     for(int j = volumes[i]; j <= m; j++) {
    //         f[i][j][0] = f[i - 1][j][0];
    //         f[i][j][1] = f[i - 1][j][1]; 
    //         for(int k = j - volumes[i]; k <= j; k++) {
    //             f[i][j][0] = min(f[i][j][0], f[i - 1][k][0] + times[i]);
    //             f[i][j][1] = min(f[i][j][1], f[i - 1][k][1] + times[i]);
    //         }
    //     }
    //     int t = volumes[i] * 2;
    //     for(int j = t; j <= m; j++) {
    //         for(int k = j - t; k <= j; k++) {
    //             f[i][j][1] = min(f[i][j][1], f[i - 1][k][0] + times[i] / 2);
    //         }
    //     }
    // }
    cout << min(f[n][m][0], f[n][m][1]) << endl;
    return 0;
}