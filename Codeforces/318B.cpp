#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<int> a, b;
    string heavy = "heavy", metal = "metal";
    for (int l = 0; l < n - 4;) {
        int flag = true;
        int r = l;
        for (; r < l + 5; r++) {
            if (str[r] != heavy[r - l]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            a.push_back(r - 1);
        }
        if (l == r) l = r + 1;
        else l = r;
    }
    for (int l = 0; l < n - 4;) {
        int flag = true;
        int r = l;
        for (; r < l + 5; r++) {
            if (str[r] != metal[r - l]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            b.push_back(l);
        }
        if (l == r) l = r + 1;
        else l = r;
    }
    int p1 = 0, p2 = 0;
    long long res = 0;
    while (p1 < a.size() && p2 < b.size()) {
        while (p2 < b.size() && b[p2] < a[p1]) {
            p2++;
        }
        if (p2 >= b.size()) {
            break;
        }
        res += b.size() - p2;
        p1++;
    }
    cout << res << endl;
    return 0;
}