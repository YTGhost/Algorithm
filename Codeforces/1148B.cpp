#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if (k >= n || k >= m) {
        cout << -1 << endl;
        return 0;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = k - i;
        if (cnt < 0) break;
        int pos = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
        if (pos + cnt >= m) {
            cout << -1 << endl;
            return 0;
        }
        res = max(res, b[pos + cnt] + tb);
    }
    cout << res << endl;
    return 0;
}