class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int memo[n][n];
        auto helper = [&](int i, int j, int target) -> int {
            memset(memo, -1, sizeof(memo));
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if(i >= j) return 0;
                int &res = memo[i][j];
                if(res != -1) return res;
                res = 0;
                if(nums[i] + nums[i + 1] == target) res = max(res, dfs(i + 2, j) + 1);
                if(nums[j] + nums[j - 1] == target) res = max(res, dfs(i, j - 2) + 1);
                if(nums[i] + nums[j] == target) res = max(res, dfs(i + 1, j - 1) + 1);
                return res;
            };
            return dfs(i, j);
        };
        int res1 = helper(2, n - 1, nums[0] + nums[1]);
        int res2 = helper(0, n - 3, nums[n - 1] + nums[n - 2]);
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]);
        return max({res1, res2, res3}) + 1;
    }
};