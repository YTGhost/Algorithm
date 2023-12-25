class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size(), res = 0, l = 0;
        unordered_map<char, int> m;
        for(int r = 0; r < n; r++) {
            m[s[r]]++;
            while(m.size() > k) {
                m[s[l]]--;
                if(m[s[l]] == 0) {
                    m.erase(s[l]);
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};