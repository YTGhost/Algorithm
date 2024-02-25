#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;
int s, t, n;

struct Range{
    int l, r;
    
    bool operator< (const Range& t) const {
        return l < t.l;
    }
}ranges[N];

int main()
{
    cin >> s >> t >> n;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    sort(ranges, ranges + n);
    int res = 0;
    bool isSuccess = false;
    for(int i = 0; i < n; i++) {
        int j = i, r = -INF;
        while(j < n && ranges[j].l <= s) {
            r = max(r, ranges[j].r);
            j++;
        }
        if(r < s) {
            res = -1;
            break;
        }
        res++;
        if(r >= t) {
            isSuccess = true;
            break;
        }
        s = r;
        i = j - 1;
    }
    if(isSuccess) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}