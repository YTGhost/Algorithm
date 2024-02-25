class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.length();
        int cnt = 0;
        for(int i = 0; i < n / 2; i++) {
            if(set.count(s[i])) cnt++;
            if(set.count(s[n - 1 - i])) cnt--;
        }
        return cnt == 0;
    }
};