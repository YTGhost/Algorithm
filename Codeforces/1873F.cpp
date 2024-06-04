#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> prefixSum(n + 1);
    for(int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int l = 1, r = n + 1;
    function<bool(int)> check = [&](int target) {
        int l = 0, r = 0;
        while (r < n) {
            if (l == r || h[r - 1] % h[r] == 0) {
                int len = r - l + 1;
                if (len == target) {
                    if (prefixSum[r + 1] - prefixSum[l] <= k) {
                        return true;
                    } else {
                        l++;
                        r++;
                    }
                } else {
                    r++;
                }
            } else {
                l = r;
            }
        }
        return false;
    };
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1 << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}