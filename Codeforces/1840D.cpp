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
    sort(nums.begin(), nums.end());
    function<bool(int)> check = [&](int target) {
        auto p1 = upper_bound(nums.begin(), nums.end(), nums[0] + 2 * target);
        if (p1 == nums.end()) {
            return true;
        }
        auto p2 = upper_bound(nums.begin(), nums.end(), nums[p1 - nums.begin()] + 2 * target);
        if (p2 == nums.end()) {
            return true;
        }
        if (nums[p2 - nums.begin()] + 2 * target >= nums[n - 1]) {
            return true;
        }
        return false;
    };
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
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