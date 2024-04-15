#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -INF));
    dp[0][0] = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        ll att, price, cost, upgrade, lvmax;
        cin >> att >> price >> cost >> upgrade >> lvmax;
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            for(int k = 0; k <= lvmax; k++) {
                ll sum = price + k * cost;
                if(sum > j) {
                    break;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j - sum] + att + k * upgrade);
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res << endl;
    return 0;
}