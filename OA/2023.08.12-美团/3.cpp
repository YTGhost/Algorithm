#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> s(n + 1, vector<long long>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> s[i][j], s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    long long total = s[n][m];
    long long res = LLONG_MAX;
    for(int i = 1; i <= n - 1; i++) {
        long long sum = s[i][m];
        res = min(res, abs(2 * sum - total));
    }
    for(int i = 1; i <= m - 1; i++) {
        long long sum = s[n][i];
        res = min(res, abs(2 * sum - total));
    }
    cout << res << endl;
    return 0;
}