#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 5; i++) {
        if (a < b && a < c) {
            a++;
        } else if (b < a && b < c) {
            b++;
        } else if (c < a && c < b) {
            c++;
        } else if (a == b) {
            a++;
        } else if (b == c) {
            b++;
        } else if (a == c) {
            a++;
        }
    }
    cout << a * b * c << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}