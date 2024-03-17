class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> t;
        function<bool(int, int)> check = [&](int l, int r) {
            while(l < r) {
                if(s[l++] != s[r--]) return false;
            }
            return true;
        };
        function<void(int)> dfs = [&](int idx) {
            if(idx == n) {
                res.push_back(t);
                return;
            }
            for(int i = idx; i < n; i++) {
                if(check(idx, i)) {
                    t.push_back(s.substr(idx, i - idx + 1));
                    dfs(i + 1);
                    t.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};