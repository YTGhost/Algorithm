class Solution {
public:
    int hash[26];
    vector<int> findAnagrams(string s, string p) {
        for(auto c : p) {
            hash[c - 'a']++;
        }
        int l = 0, r = 0, n = s.length(), m = p.length();
        vector<int> res;
        while(r < n) {
            hash[s[r] - 'a']--;
            while(l <= r && hash[s[r] - 'a'] < 0) {
                hash[s[l++] - 'a']++;
            }
            if(r - l + 1 == m) res.push_back(l);
            r++;
        }
        return res;
    }
};