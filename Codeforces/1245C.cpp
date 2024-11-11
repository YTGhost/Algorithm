#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    for (auto c : str) {
        if (c == 'w' || c == 'm') {
            cout << 0 << endl;
            return 0;
        }
    }
    vector<long long> f(n + 1);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1];
        if (str[i - 1] == str[i - 2] && (str[i - 1] == 'u' || str[i - 1] == 'n')) {
            f[i] = (f[i] + f[i - 2]) % MOD;
        }
    }
    cout << f[n] << endl;
    return 0;
}