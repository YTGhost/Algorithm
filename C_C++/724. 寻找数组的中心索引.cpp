class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        vector<int> lsum(n, 0);
        vector<int> rsum(n, 0);
        for(int i = 0, sum = 0; i < n; i++)
            lsum[i] = sum, sum += nums[i];
        for(int i = n-1, sum = 0; i >= 0; i--)
            rsum[i] = sum, sum += nums[i];
        int res = -1;
        for(int i = 0; i < n; i++)
            if(lsum[i] == rsum[i]) {
                res = i;
                break;
            }
        return res;
    }
};