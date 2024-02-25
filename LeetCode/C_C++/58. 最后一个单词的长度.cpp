class Solution {
public:
    int ans;
    int lengthOfLastWord(string s) {
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                if(ans == 0) continue;
                else return ans;
            }
            ans++;
        }
        return ans;
    }
};