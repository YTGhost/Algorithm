class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string str = "";
        int minLength = INT_MAX;
        for(int i = 0; i < strs.size(); i++) minLength = minLength < strs[i].size() ? minLength : strs[i].size();
        int i = 0;
        while(i != minLength)
        {
            char t = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != t) return str; 
            }
            str += t;
            i++;
        }
        return str;
    }
};