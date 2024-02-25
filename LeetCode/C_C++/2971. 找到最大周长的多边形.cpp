class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1);
        prefixSum[0] = 0;
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return prefixSum;
    }
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum = getPrefixSum(nums);
        long long res = -1;
        for(int i = n - 1; i >= 2; i--) {
            if(prefixSum[i] > nums[i]) {
                res = prefixSum[i + 1];
                break;
            }
        }
        return res;
    }
    
};