// LeetCode究极班打卡
class Solution {
public:
    string convert(string s, int n) {
        string ans;
        if(n == 1) return s;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || i == n-1)
            {
                for(int j = i; j < s.size(); j += 2*n-2)
                    ans += s[j];
            }else{
                for(int j = i, k = 2*n-2-i; j < s.size() || k < s.size(); j += 2*n-2, k += 2*n-2)
                {
                    if(j < s.size()) ans += s[j];
                    if(k < s.size()) ans += s[k];
                }
            }
        }
        return ans;
    }
};