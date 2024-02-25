class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int l = 0, r = n, idx = 0;
        vector<int> res(n + 1);
        for(int i = 0; i < n; i++) {
            res[idx++] = s[i] == 'I' ? l++ : r--;
        }
        res[idx] = l;
        return res;
    }
};