#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int p1 = 0, p2 = 0;
    vector<int> res;
    while(p1 < n && p2 < m) {
        if(s[p1] == t[p2]) {
            res.push_back(p2 + 1);
            p1++;
            p2++;
        } else {
            p2++;
        }
    }
    for(int i = 0; i < res.size(); i++) {
        if(i == res.size() - 1) {
            cout << res[i] << endl;
        } else {
            cout << res[i] << " ";
        }
    }
    return 0;
}