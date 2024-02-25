// 01背包变体

// 朴素版（二维）
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for(int num : nums) sum += num;
        if(sum % 2 != 0) return false;
        vector<vector<bool>> f(size+1, vector<bool>((sum>>=1)+1, false));
        for(int i = 0; i <= size; i++) f[i][0] = true;

        for(int i = 1; i <= size; i++)
            for(int j = 0; j <= sum; j++)
            {
                f[i][j] = f[i-1][j];
                if(j >= nums[i-1]) f[i][j] = f[i][j] | f[i-1][j-nums[i-1]];
            }
        return f[size][sum];
    }
};

// 优化（一维）
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for(int num : nums) sum += num;
        if(sum % 2 != 0) return false;
        vector<bool> f((sum>>=1)+1, false);
        f[0] = true;

        for(int i = 1; i <= size; i++)
            for(int j = sum; j >= nums[i-1]; j--)
                f[j] = f[j] || f[j-nums[i-1]];

        return f[sum];
    }
};

