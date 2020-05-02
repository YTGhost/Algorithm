class Solution {
public:
    int map[128];
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for(int i = 0, j = 0; j < s.length(); j++)
        {
            map[s[j]]++;
            while(map[s[j]] > 1) map[s[i++]]--;
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};