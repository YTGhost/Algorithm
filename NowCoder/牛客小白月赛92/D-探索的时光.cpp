#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    ll res = LLONG_MAX;
    // 推公式，枚举x，O(n)
    ll a = 0, b = 0, c = 0;
    for(int i = 1; i <= n; i++) {
        a += nums[i];
        b += 1LL * i * nums[i];
        c += 1LL * i * i * nums[i];
    }
    for(ll x = 1; x <= n; x++) {
        res = min(res, x * x * a - 2 * x * b + c);
    }
    cout << res << endl;
    return 0;
}