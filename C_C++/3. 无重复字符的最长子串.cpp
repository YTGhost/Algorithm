class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int n = s.size(), res = 0, left = 0;
        for(int right = 0; right < n; right++) {
            char c = s[right];
            m[c]++;
            while(m[c] > 1) {
                m[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

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