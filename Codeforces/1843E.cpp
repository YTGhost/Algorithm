#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segments;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }
    int q;
    cin >> q;
    vector<int> changes(q + 1);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        changes[i] = x;
    }
    function<bool(int)> check = [&](int target) {
        vector<int> nums(n + 1, 0);
        for (int i = 1; i <= target; i++) {
            nums[changes[i]] = 1;
        }
        vector<int> preSum(nums.size() + 1);
        for (int i = 1; i <= n; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (auto segment : segments) {
            int l = segment.first, r = segment.second;
            int sum = preSum[r + 1] - preSum[l];
            if (2 * sum > (r - l + 1)) {
                return true;
            }
        }
        return false;
    };
    int l = 1, r = q + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (l == q + 1) cout << -1 << endl;
    else cout << l << endl;
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