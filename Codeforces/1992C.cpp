#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> res;
    for (int i = n; i > m; i--) {
        res.push_back(i);
    }
    sort(res.rbegin(), res.rend());
    for (int i = 1; i <= m; i++) {
        res.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
        if (i == n - 1) {
            cout << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}