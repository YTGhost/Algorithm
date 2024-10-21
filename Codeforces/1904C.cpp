#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }
    sort(nums.begin(), nums.end());
    long long diff = nums[0];
    for (int i = 1; i < n; i++) {
        diff = min(diff, nums[i] - nums[i - 1]);
    }
    if (k == 1) {
        cout << diff << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long val = nums[j] - nums[i];
            int pos = lower_bound(nums.begin(), nums.end(), val) - nums.begin();
            if (pos < n) {
                diff = min(diff, nums[pos] - val);
            }
            if (pos > 0) {
                diff = min(diff, val - nums[pos - 1]);
            }
        }
    }
    cout << diff << endl;
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