#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n);
    ll res = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i].first >> nums[i].second;
        sum += nums[i].first;
    }
    for(int i = 0; i < n; i++) {
        sum -= nums[i].first;
        sum += nums[i].second;
        res = max(res, sum);
        sum += nums[i].first;
        sum -= nums[i].second;
    }
    cout << res << endl;
    return 0;
}