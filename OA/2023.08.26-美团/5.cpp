#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> prefixSum(n + 1);
    for(int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    unordered_map<long long, int> mp;
    int res = 0;
    for(int i = 0; i <= n; i++) {
        auto it = mp.find(prefixSum[i] - k * i);
        if(it != mp.end()) {
            res = max(res, i - it->second);
        } else {
            mp[prefixSum[i] - k * i] = i;
        }
    }
    cout << res << endl;
    return 0;
}