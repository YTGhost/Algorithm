class NumArray {
public:
    vector<int> prefixSum;
    vector<int> getPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return prefixSum;
    }
    NumArray(vector<int>& nums) {
        prefixSum = getPrefixSum(nums);
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

class NumArray {
public:
    vector<int> pre;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre = vector<int>(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pre[i] = pre[i-1] + nums[i-1];
    }
    
    int sumRange(int i, int j) {
        return pre[j+1] - pre[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */