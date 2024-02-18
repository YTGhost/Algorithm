class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        int maxCnt = 0;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            m1[s[i] - 'a']++;
            maxCnt = max(maxCnt, m1[s[i] - 'a']);
            m2[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> t;
        for(int i = 0; i < 26; i++) {
            if(m1[i] == maxCnt) {
                t.push_back({m2[i], i});
            }
        }
        ranges::sort(t);
        string res = "";
        for(auto item : t) {
            res += 'a' + item.second;
        }
        return res;
    }
};