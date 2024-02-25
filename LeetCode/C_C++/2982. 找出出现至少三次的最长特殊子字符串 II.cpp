class Solution {
public:
    int maximumLength(string s) {
        vector<int> groups[26];
        int cnt = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            cnt++;
            if(i + 1 == n || s[i] != s[i + 1]) {
                groups[s[i] - 'a'].push_back(cnt);
                cnt = 0;
            }
        }
        int res = 0;
        for(auto &group : groups) {
            if(group.empty()) continue;
            sort(group.rbegin(), group.rend());
            group.push_back(0);
            group.push_back(0);
            res = max({res, group[0] - 2, min(group[0] - 1, group[1]), group[2]});
        }
        return res ? res : -1;
    }
};