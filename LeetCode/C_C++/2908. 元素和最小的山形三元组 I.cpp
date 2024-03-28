// O(n)
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for(int i = n - 2; i > 1; i--) {
            suf[i] = min(nums[i], suf[i + 1]);
        }
        int res = INT_MAX;
        int pre = nums[0];
        for(int i = 1; i < n - 1; i++) {
            if(pre < nums[i] && nums[i] > suf[i + 1]) {
                res = min(res, pre + nums[i] + suf[i + 1]);
            }
            pre = min(pre, nums[i]);
        }
        return res == INT_MAX ? -1 : res;
    }
};

// O(n^3)
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int sum = INT_MAX;
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] < nums[j] && nums[k] < nums[j]) {
                        sum = min(sum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        return sum == INT_MAX ? -1 : sum;
    }
};