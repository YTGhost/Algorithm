#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    ll sum = 0;
    unordered_map<ll, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        sum += nums[i];
        mp[nums[i]]++;
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        ll remain = sum - nums[i];
        if (remain % 2 == 0) {
            ll t = remain / 2;
            if (t != nums[i] && mp.contains(t)) {
                res.push_back(i);
            } else if (t == nums[i] && mp[t] >= 2) {
                res.push_back(i);
            }
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        if (i == 0) cout << res[i];
        else cout << " " << res[i];
    }
    return 0;
}