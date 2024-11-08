#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;
    if (m == 1 && s == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    if (m > 1 && s == 0) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    if (s > 9 * m) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    vector<int> res(m + 1);
    int temp = s - 1;
    res[1] = 1;
    for (int i = m; i >= 1 && temp; i--) {
        if (temp >= 9) {
            res[i] += 9;
            temp -= 9;
        } else {
            res[i] += temp;
            break;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i];
    }
    cout << " ";

    temp = s;
    res = vector<int>(m + 1);
    for (int i = 1; i <= m && temp; i++) {
        if (temp >= 9) {
            res[i] += 9;
            temp -= 9;
        } else {
            res[i] += temp;
            break;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i];
    }
    cout << endl;
    return 0;
}