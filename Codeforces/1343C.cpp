#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sgn(int x) {
    if(x > 0) return 1;
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll sum = 0;
    for(int l = 0; l < n;) {
        int r = l + 1;
        int val = nums[l];
        while(r < n && sgn(nums[l]) == sgn(nums[r])) {
            val = max(val, nums[r]);
            r++;
        }
        sum += val;
        l = r;
    }
    cout << sum << endl;
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