// DP题，类似打家劫舍
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> red(n);
    vector<int> green(n);
    for(int i = 0; i < n; i++) {
        cin >> red[i] >> green[i];
    }
    vector<vector<long long>> f(n, vector<long long>(3, 0LL));
    f[0][1] = red[0];
    f[0][2] = green[0];
    for(int i = 1; i < n; i++) {
        f[i][0] = max(f[i - 1][1], f[i - 1][2]);
        f[i][1] = max(f[i - 1][0], f[i - 1][2]) + red[i];
        f[i][2] = max(f[i - 1][0], f[i - 1][1]) + green[i];
    }
    cout << max({f[n - 1][0], f[n - 1][1], f[n - 1][2]}) << endl;
    return 0;
}