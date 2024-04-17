#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int res1 = 0, res2 = 0;
    vector<int> prefixSum(n + 1, 0);
    prefixSum[0] = 1;
    for(int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] * (nums[i] > 0 ? 1 : -1);
    }
    unordered_map<int, int> mp;
    for(int i = 0; i <= n; i++) {
        if(prefixSum[i] == 1) {
            res1 += mp[-1];
            res2 += mp[1];
        } else {
            res1 += mp[1];
            res2 += mp[-1];
        }
        mp[prefixSum[i]]++;
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}