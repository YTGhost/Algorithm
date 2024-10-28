#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }
    string res(n, '0');
    int l = n, r = 0;
    for (int m = 1; m <= n; m++) {
        l = min(l, p[m]);
        r = max(r, p[m]);
        if (r - l + 1 == m) {
            res[r - l] = '1';
        }
    }
    cout << res << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}