#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 1);
    unordered_map<int, int> val2idx;
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
        val2idx[nums[i]] = i;
    }
    int res = INT_MAX;
    set<int> s;
    for(int i = 1; i <= k; i++) {
        s.insert(val2idx[i]);
    }
    for(int end = k; end <= n; end++) {
        int start = end - k + 1;
        res = min(res, *s.rbegin() - *s.begin());
        s.erase(val2idx[start]);
        s.insert(val2idx[end + 1]);
    }
    cout << res << endl;
    return 0;
}