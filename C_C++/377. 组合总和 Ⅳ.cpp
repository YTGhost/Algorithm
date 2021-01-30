class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unsigned long long> f(target+1, 0);
        f[0] = 1;
        for(int i = 1; i <= target; i++)
            for(auto num : nums)
                if(i >= num) f[i] += f[i-num];
        return f[target];
    }
};