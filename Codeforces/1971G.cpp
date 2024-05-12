#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, priority_queue<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        mp[nums[i] >> 2].push(-nums[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << -mp[nums[i] >> 2].top() << " ";
        mp[nums[i] >> 2].pop();
    }
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