class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int limit;
    void dfs(int n, int index) {
        if(path.size() == limit) {
            res.push_back(path);
            return;
        }
        for(int i = index; i <= n; i++) {
            path.push_back(i);
            dfs(n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        limit = k;
        dfs(n, 1);
        return res;
    }
};