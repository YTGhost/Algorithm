#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, long long> mp;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int x;
    cin >> x;
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
    }
    long long res = 0LL;
    bool flag = true;
    while(flag) {
        bool t = false;
        unordered_map<int, long long> newMp;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            int level = it->first;
            long long cnt = it->second;
            if(level <= x) {
                if(level == x) res = max(res, cnt);
                continue;
            }
            t = true;
            int newLevel = (level + 2) / 3;
            newMp[newLevel] += 2 * cnt;
        }
        flag = t;
        mp = newMp;
    }
    cout << res << endl;
    return 0;
}