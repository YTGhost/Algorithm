class Solution {
public:
    void reverse(string& s, int l, int r) {
        while(l < r) swap(s[l++], s[r--]);
    }
    string reverseStr(string s, int k) {
        for(int i = 0; i < s.length(); i++) {
            int len = s.length() - i;
            if(len < k) {
                reverse(s, i, s.length() - 1);
                break;
            } else if(len < 2 * k && len >= k) {
                reverse(s, i, i + k - 1);
                break;
            }
            reverse(s, i, i + k - 1);
            i = i + 2 * k - 1;
        }
        return s;
    }
};