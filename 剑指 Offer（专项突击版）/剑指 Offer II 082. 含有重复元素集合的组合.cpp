class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int k;
    void dfs(vector<int>& candidates, int index, int sum) {
        if(sum == k) {
            res.push_back(path);
            return;
        }
        if(sum > k) {
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        k = target;
        dfs(candidates, 0, 0);
        return res;
    }
};