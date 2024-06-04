#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int m;
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) {
        cin >> d[i];
    }
    if (find(b.begin(), b.end(), d[m - 1]) == b.end()) {
        cout << "NO" << endl;
        return;
    }
    multiset st(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            if (!st.contains(b[i])) {
                cout << "NO" << endl;
                return;
            }
            st.extract(b[i]);
        }
    }
    cout << "YES" << endl;
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