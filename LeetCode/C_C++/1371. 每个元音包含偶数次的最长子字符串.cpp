class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> pre(1 << 5, INT_MAX);
        int state = 0, ans = 0;
        pre[0] = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a') state ^= 1 << 4;
            else if(s[i] == 'e') state ^= 1 << 3;
            else if(s[i] == 'i') state ^= 1 << 2;
            else if(s[i] == 'o') state ^= 1 << 1;
            else if(s[i] == 'u') state ^= 1;
            if(pre[state] == INT_MAX) pre[state] = i;
            else ans = max(ans, i - pre[state]);
        }
        return ans;
    }
};