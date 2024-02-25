class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& res, int target, int num, int start, int limit, vector<int>& temp) {
        if(start > 10) return;
        if(num > limit) return;
        if(num == limit && !target) {
            res.emplace_back(temp);
            return;
        }
        for(int i = start; i <= 9; i++)
        {
            temp.emplace_back(i);
            dfs(res, target-i, num+1, i+1, limit, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        dfs(res, n, 0, 1, k, temp);
        return res;
    }
};