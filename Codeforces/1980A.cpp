#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    vector<int> hash(7, 0);
    for (int i = 0; i < n; i++) {
        hash[a[i] - 'A']++;
    }
    int res = 0;
    for (int i = 0; i < 7; i++) {
        int cnt = m - hash[i];
        if (cnt > 0) {
            res += cnt;
        }
    }
    cout << res << endl;
    return;
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