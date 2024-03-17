class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> combination;
        vector<bool> visit(n, false);
        function<void(int, int)> dfs = [&](int idx, int sum) {
            if(idx == n) return;
            if(sum == target) {
                res.push_back(combination);
                return;
            }
            if(sum > target) {
                return;
            }
            dfs(idx + 1, sum);
            combination.push_back(candidates[idx]);
            dfs(idx, sum + candidates[idx]);
            combination.pop_back();
        };
        dfs(0, 0);
        return res;
    }
};

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