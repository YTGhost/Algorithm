#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    vector<vector<char>> g(5, vector<char>(n));
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
            if((i == 1 || i == 3) && g[i][j] == '*') {
                cnt++;
                g[i][j] = '.';
            }
        }
    }
    
    if(cnt <= h) {
        h -= cnt;
        res += cnt;
    } else {
        cout << h << endl;
        return 0;
    }

    int cnt1 = 0, cnt2 = 0; 
    for(int i = 0; i < n; i++) {
        if(g[0][i] == '*') {
            if(g[1][i] == '.') {
                cnt1++;
            } else {
                cnt2++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(g[4][i] == '*') {
            if(g[3][i] == '.') {
                cnt1++;
            } else {
                cnt2++;
            }
        }
    }
    if(cnt1 <= h) {
        h -= cnt1;
        res += cnt1;
    } else {
        res += h;
        cout << res << endl;
        return 0;
    }
    if(cnt2 * 2 <= h) {
        h -= cnt2 * 2;
        res += cnt2;
    } else {
        int t = h / 2;
        res += t;
        h -= t * 2;
    }
    cout << res << endl;
    return 0;
}