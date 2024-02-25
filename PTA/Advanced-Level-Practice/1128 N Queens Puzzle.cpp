#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int row[N], dg[2 * N], udg[2 * N];

int main()
{
    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        memset(row, 0, sizeof row);
        memset(dg, 0, sizeof dg);
        memset(udg, 0, sizeof udg);
        bool success = true;
        for(int y = 1; y <= n; y++) {
            int x;
            cin >> x;
            if(row[x] || dg[x + y] || udg[y - x + n]) success = false;
            row[x] = dg[x + y] = udg[y - x + n] = 1;
        }
        if(success) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}