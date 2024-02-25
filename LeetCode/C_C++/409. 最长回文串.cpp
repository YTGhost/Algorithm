class Solution {
public:
    int a[58];
    int sum;
    int longestPalindrome(string s) {
        for(int i = 0; i < s.length(); i++)
        {
            a[s[i] - 'A']++;
        }
        for(auto item : a)
        {
            sum += item - (item & 1);
        }
        return sum < s.length() ? ++sum : sum;
    }
};