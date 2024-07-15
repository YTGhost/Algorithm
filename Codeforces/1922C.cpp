#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<int> prefixSum(n + 1, 1);
    vector<int> suffixSum(n + 1, 1);
    prefixSum[1] = 0;
    suffixSum[n] = 0;
    for (int i = 2; i < n; i++) {
        int cost;
        if (nums[i + 1] - nums[i] < nums[i] - nums[i - 1]) {
            cost = 1;
        } else {
            cost = nums[i + 1] - nums[i];
        }
        prefixSum[i + 1] = prefixSum[i] + cost;
    }
    for (int i = n - 1; i > 1; i--) {
        int cost;
        if (nums[i] - nums[i - 1] < nums[i + 1] - nums[i]) {
            cost = 1;
        } else {
            cost = nums[i] - nums[i - 1];
        }
        suffixSum[i - 1] = suffixSum[i] + cost;
    } 
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x < y) {
            cout << prefixSum[y] - prefixSum[x] << endl;
        } else {
            cout << suffixSum[y] - suffixSum[x] << endl;
        }
    }
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