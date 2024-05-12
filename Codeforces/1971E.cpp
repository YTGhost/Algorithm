#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(k);
        vector<int> b(k);
        for(int i = 0; i < k; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < k; i++) {
            cin >> b[i];
        }
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++) {
            mp[a[i]] = b[i];
        }
        for(int i = 0; i < q; i++) {
            ll d;
            cin >> d;
            if(mp.count(d)) {
                cout << mp[d] << " ";
                continue;
            }
            int l = lower_bound(a.begin(), a.end(), d + 1) - a.begin() - 1;
            int r = lower_bound(a.begin(), a.end(), d) - a.begin();
            if(l == -1) {
                cout << d * mp[a[r]] / a[r] << " ";
                continue;
            }
            cout << mp[a[l]] + (d - a[l]) * (mp[a[r]] - mp[a[l]]) / (a[r] - a[l]) << " ";
        }
        cout << endl;
    }
    return 0;
}