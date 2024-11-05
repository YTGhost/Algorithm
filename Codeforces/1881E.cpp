#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> f(n);
    f[n - 1] = 1;
    function<int(int)> handle = [&](int pos) {
        if (pos > n) {
            return n + 1;
        }
        if (pos == n) {
            return 0;
        }
        return f[pos];
    };
    for (int i = n - 2; i >= 0; i--) {
        f[i] = min(f[i + 1] + 1, handle(i + nums[i] + 1));
    }
    cout << f[0] << endl;
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