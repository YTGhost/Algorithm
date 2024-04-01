#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1));
    vector<vector<long long>> s(n + 1, vector<long long>(m + 1, 0LL));
    long long total = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j], s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + g[i][j];
            total += g[i][j];
        }
    }
    long long res = LLONG_MAX;
    long long half = total / 2;
    function<bool(int, int, int)> check = [&](int i, int j, int len) {
        int x = i + len - 1, y = j + len - 1;
        return s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] >= half;
    };
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int l = 1, r = min(n - i + 1, m - j + 1) + 1;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(check(i, j, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if(l == min(n - i + 1, m - j + 1) + 1) {
                l--;
                int len = l;
                int x = i + len - 1, y = j + len - 1;
                long long sum = s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1];
                long long rest = total - sum;
                res = min(res, abs(sum - rest));
                continue;
            }
            int len = l;
            int x = i + len - 1, y = j + len - 1;
            long long sum = s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1];
            long long rest = total - sum;
            res = min(res, abs(sum - rest));
            len -= 1;
            x = i + len - 1, y = j + len - 1;
            sum = s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1];
            rest = total - sum;
            res = min(res, abs(sum - rest));
        }
    }
    cout << res << endl;
    return 0;
}