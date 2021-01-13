class Solution {
public:
    void reverse(string& s, int start, int end) {
        while(start < end) swap(s[start++], s[end--]);
    }
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.length()-1);
        reverse(s, 0, s.length()-1-n);
        reverse(s, s.length()-n, s.length()-1);
        return s;
    }
};