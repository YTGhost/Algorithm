#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (int k = n; k >= 1; k--) {
        vector<int> t(n), end(n + 1);
        for (int i = 0; i < n; i++) {
            t[i] = str[i] - '0';
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt -= end[i];
            t[i] ^= (cnt & 1);
            if (t[i] == 0) {
                if (i < n - k + 1) {
                    end[k + i]++;
                    cnt++;
                    t[i] = 1;
                } else {
                    break;
                }
            }
        }
        bool flag = true;
        for (int i = 1; i < k; i++) {
            if (t[n - i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << k << endl;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}