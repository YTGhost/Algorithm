class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& temp, int index) {
        if(candidates.size() == index) return;
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        if(target < 0) return;
        dfs(candidates, target, temp, index+1);
        if(target-candidates[index] >= 0)
        {
            temp.push_back(candidates[index]);
            dfs(candidates, target-candidates[index], temp, index);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, target, temp, 0);
        return res;
    }
};