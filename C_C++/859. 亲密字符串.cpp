class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        vector<int> cnt1(26), cnt2(26);
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            int a = s[i] - 'a', b = goal[i] - 'a';
            cnt1[a]++, cnt2[b]++;
            if(a != b) sum++;
        }
        bool flag = false;
        for(int i = 0; i < 26; i++) {
            if(cnt1[i] != cnt2[i]) return false;
            if(cnt1[i] > 1) flag = true;
        }
        return sum == 2 || sum == 0 && flag;
    }
};