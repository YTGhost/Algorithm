class Solution {
public:
    vector<vector<int>> res;
    void dfs(int n, int k, int count, vector<int>& path) {
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = count+1; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k, i, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k == 0) return res;
        vector<int> path;
        dfs(n, k, 0, path);
        return res;
    }
};