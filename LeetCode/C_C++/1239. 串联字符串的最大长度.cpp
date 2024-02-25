class Solution {
public:
    vector<int> masks;
    int res;
    void dfs(int pos, int mask) {
        if (pos == masks.size()) {
            res = max(res, __builtin_popcount(mask));
            return;
        }
        if ((mask & masks[pos]) == 0) {
            dfs(pos + 1, mask | masks[pos]);
        }
        dfs(pos + 1, mask);
    };
    int maxLength(vector<string> &arr) {
        for(auto &str : arr) {
            int mask = 0;
            for(auto c : str) {
                int t = c - 'a';
                if((mask >> t) & 1) {
                    mask = 0;
                    break;
                }
                mask |= 1 << t;
            }
            if(mask > 0) masks.push_back(mask);
        }
        dfs(0, 0);
        return res;
    }
};