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
    vector<int> res;
    res.push_back(nums[0]);
    int r = 1;
    bool flag;
    while (r < n) {
        if (nums[r] > nums[r - 1]) {
            r++;
            while (r < n && nums[r] > nums[r - 1]) {
                r++;
            }
        } else {
            r++;
            while (r < n && nums[r] < nums[r - 1]) {
                r++;
            }
        }
        res.push_back(nums[r - 1]);
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i == res.size() - 1) cout << res[i] << endl;
        else cout << res[i] << " ";
    }
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