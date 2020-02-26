class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
        {
            return true;
        }
        for(int i = 0, j = 0; i < t.length(); i++)
        {
            if(s[j] == t[i]){
                if(++j == s.length()){
                    return true;
                }
            }
        }
        return false;
    }
};