#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> nums1(n + 1);
    vector<long long> nums2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> nums2[i];
    }
    vector<vector<long long>> f(n + 1, vector<long long>(3));
    f[1][0] = nums1[1];
    f[1][1] = nums2[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = max({f[i - 1][2] + nums1[i], f[i - 1][1] + nums1[i], nums1[i]});
        f[i][1] = max({f[i - 1][2] + nums2[i], f[i - 1][0] + nums2[i], nums2[i]});
        f[i][2] = max(f[i - 1][0], f[i - 1][1]);
    }
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;
}