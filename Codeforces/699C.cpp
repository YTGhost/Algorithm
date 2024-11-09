#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> f(n + 1, vector<int>(3));
    for (int i = 1; i <= n; i++) {
        if (nums[i] == 0) {
            f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
        } else if (nums[i] == 1) {
            f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
            f[i][1] = max({f[i - 1][0] + 1, f[i - 1][2] + 1});
        } else if (nums[i] == 2) {
            f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
            f[i][2] = max({f[i - 1][0] + 1, f[i - 1][1] + 1});
        } else {
            f[i][0] = max({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
            f[i][1] = max({f[i - 1][0] + 1, f[i - 1][2] + 1});
            f[i][2] = max({f[i - 1][0] + 1, f[i - 1][1] + 1});
        }
    }
    cout << n - max({f[n][0], f[n][1], f[n][2]}) << endl;
    return 0;
}