class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n, 0);
        vector<int> rightsum(n, 0);
        for(int i = 1; i < n; i++) {
            leftsum[i] += leftsum[i - 1] + nums[i - 1];
            rightsum[n - 1 - i] += rightsum[n - i] + nums[n - i];
        }
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            res[i] = abs(leftsum[i] - rightsum[i]);
        }
        return res;
    }
};