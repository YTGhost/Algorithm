#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int n = str.length();
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            if(str[i] != str[i - 1]) {
                cnt++;
            }
        }
        if(cnt == 0) {
            cout << 1 << endl;
            continue;
        }
        if(cnt == 1 && str[0] == '1') {
            cout << 2 << endl;
            continue;
        }
        cout << cnt << endl;
    }
    return 0;
}