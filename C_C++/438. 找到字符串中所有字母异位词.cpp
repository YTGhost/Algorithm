class Solution {
public:
    bool check(vector<int> &c1, vector<int> &c2) {
        for(int i = 0; i < 26; i++) {
            if(c1[i] != c2[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, c1(26), c2(26);
        int n = s.length(), m = p.length();
        for(int i = 0; i < m; i++) c2[p[i] - 'a']++;
        for(int l = 0, r = 0; r < n; r++) {
            c1[s[r] - 'a']++;
            if(r - l + 1 > m) c1[s[l++] - 'a']--;
            if(check(c1, c2)) res.push_back(l);
        }
        return res;
    }
};