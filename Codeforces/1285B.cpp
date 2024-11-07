#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        total += nums[i];
    }
    long long sum = 0, t = 0;
    int l = 1, r = 1;
    while (r <= n) {
        t += nums[r];
        if (l == 1 && r == n) {
            break;
        }
        sum = max(sum, t);
        if (t <= 0) {
            l = r + 1, r = l;
        } else {
            r++;
        }
    }
    if (total > sum) cout << "YES" << endl;
    else cout << "NO" << endl;
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