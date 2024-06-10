#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a; 
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = gcd(a[i], a[i + 1]);
    }
    int bad = 0;
    for (int i = 1; i < n - 1; i++) {
        bad += b[i] < b[i - 1];
    }
    int res = 0;
    if (bad - (b[1] < b[0]) == 0) {
        res = 1;
    }
    if (bad - (b[n - 2] < b[n - 3]) == 0) {
        res = 1;
    }
    for (int i = 1; i < n - 1; i++) {
        int tmp = bad;
        tmp -= b[i] < b[i - 1];
        int g = gcd(a[i - 1], a[i + 1]);
        if (i - 1 > 0) {
            tmp -= b[i - 1] < b[i - 2];
            tmp += g < b[i - 2];
        }
        if(i + 1 < n - 1) {
            tmp -= b[i] > b[i + 1];
            tmp += g > b[i + 1];
        }
        if (tmp == 0) {
            res = 1;
        }
    }
    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}