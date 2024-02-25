class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26];
        int b[26];
        char c;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for(int i = 0; i < s.length(); i++) a[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++)
        {
            b[t[i] - 'a']++;
            if(b[t[i] - 'a'] > a[t[i] - 'a']){
                c = 'a' + (t[i] - 'a');
                break;
            } 
        }
        return c;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int total = 0;
        for(auto c : s) total += c - 'a';
        for(auto c : t) total -= c - 'a';
        return 'a' + abs(total);
    }
};