class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& temp, int index) {
        if(target < 0) return;
        if(target == 0) {
            res.emplace_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                if(i > index && candidates[i] == candidates[i-1]) continue;
                temp.emplace_back(candidates[i]);
                dfs(candidates, target-candidates[i], temp, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, temp, 0);
        return res;
    }
};