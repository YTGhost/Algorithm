#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll r;
    cin >> r;
    ll h = r;
    ll res = 0;
    for(ll i = 0; i <= r; i++) {
        while(i * i + h * h >= (r + 1) * (r + 1)) {
            h--;
        }
        ll t = h;
        while(i * i + t * t >= r * r && t > 0) {
            t--;
            res++;
        }
    }
    cout << res * 4 << endl;
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