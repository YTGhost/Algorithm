class Solution {
public:
    int hash[26];
    bool checkInclusion(string s1, string s2) {
        for(auto c : s1) {
            hash[c - 'a']++;
        }
        int l = 0, r = 0, n = s2.length(), m = s1.length();
        while(r < n) {
            hash[s2[r] - 'a']--;
            while(l <= r && hash[s2[r] - 'a'] < 0) {
                hash[s2[l++] - 'a']++;
            }
            if(r - l + 1 == m) return true;
            r++;
        }
        return false;
    }
};