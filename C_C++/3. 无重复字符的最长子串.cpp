// LeetCode究极班打卡
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int ans = 0;
        for(int i = 0, j = 0; i < s.length(); i++)
        {
            map[s[i]]++;          
            while(map[s[i]] > 1) map[s[j++]]--;
            ans = max(ans, i-j+1); 
        }
        return ans;
    }};

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