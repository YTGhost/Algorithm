#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        unordered_map<char, int> mp;
        for(auto c : str) {
            mp[c]++;
        }
        if(mp.size() == 1) {
            cout << "NO" << endl;
        } else {
            for(int i = 0; i < str.size(); i++) {
                if(str[i] != str[0]) {
                    swap(str[i], str[0]);
                    break;
                }
            }
            cout << "YES" << endl;
            cout << str << endl;
        }
    }
    return 0;
}