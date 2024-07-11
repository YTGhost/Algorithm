#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(k);
    int maxVal = -1;
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
        maxVal = max(maxVal, nums[i]);
    }
    long long res = 0;
    bool flag = true;
    for (int i = 0; i < k; i++) {
        if (nums[i] == maxVal && flag) {
            flag = false;
            continue;
        }
        res += nums[i] + (nums[i] - 1);
    }
    cout << res << endl;
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