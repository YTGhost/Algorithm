class Solution {
public:
    int num;
    void count(string s, int start, int end) {
        while(start >= 0 && end < s.length() && s[start] == s[end])
        {
            num++;
            start--;
            end++;
        }
    }

    int countSubstrings(string s) {
        for(int i = 0; i < s.length(); i++)
        {
            count(s, i, i);
            count(s, i, i+1);
        }
        return num;
    }
};