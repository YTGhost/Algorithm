#include <iostream>
using namespace std;

const int N = 10010;
int p[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n;
    for(int i = 1; i <= 10000; i++) p[i] = i;
    cin >> n;
    int res1 = 0, res2 = 1;
    while(n--)
    {
        int k;
        cin >> k;
        int x;
        cin >> x;
        k--;
        res2 = max(res2, x);
        while(k--)
        {
            int b;
            cin >> b;
            res2 = max(res2, b);
            int pb = find(b), px = find(x);
            if(pb != px) {
                p[pb] = px;
                res1++;
            }
        }
    }
    cout << res2 - res1 << " " << res2 << endl;
    
    int q;
    cin >> q;
    while(q--)
    {
        int x1, x2;
        cin >> x1 >> x2;
        int px1 = find(x1), px2 = find(x2);
        if(px1 == px2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}