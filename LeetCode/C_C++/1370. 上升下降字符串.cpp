class Solution {
public:
    int hash[26];
    string sortString(string s) {
        string res = "";
        for(auto c : s) hash[c - 'a']++;
        while(res.length() != s.length())
        {
            for(int i = 0; i < 26; i++)
            {
                if(hash[i]) {
                    res += 'a' + i;
                    hash[i]--;
                }
            }
            for(int i = 25; i >= 0; i--)
            {
                if(hash[i]) {
                    res += 'a' + i;
                    hash[i]--;
                }
            }
        }
        return res;
    }
};