#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> f(n + 1);
    f[a] = 1, f[b] = 1, f[c] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= a && f[i - a]) {
            f[i] = max(f[i], f[i - a] + 1);
        }
        if (i >= b && f[i - b]) {
            f[i] = max(f[i], f[i - b] + 1);
        }
        if (i >= c && f[i - c]) {
            f[i] = max(f[i], f[i - c] + 1);
        }
    }
    cout << f[n] << endl;
    return 0;
}