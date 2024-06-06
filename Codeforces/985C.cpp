#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    ll res = 0;
    int rg = upper_bound(nums.begin(), nums.end(), nums[0] + l) - nums.begin();
    if (rg < n) {
        cout << 0 << endl;
        return 0;
    }
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        res += nums[idx++];
        for (int j = 0; j < k - 1; j++) {
            if (rg - idx > n - i) {
                idx++;
            } else {
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}