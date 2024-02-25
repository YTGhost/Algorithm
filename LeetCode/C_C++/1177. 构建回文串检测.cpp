class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<bool> res;
        vector<int> cnt(n + 1);
        for(int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i] ^ (1 << (s[i] - 'a'));
        }
        for(auto query : queries) {
            int l = query[0], r = query[1], k = query[2];
            int num = 0, x = cnt[r + 1] ^ cnt[l];
            while(x > 0) {
                x &= x - 1;
                num++;
            }
            res.push_back(num <= (2 * k + 1));
        }
        return res;
    }
};