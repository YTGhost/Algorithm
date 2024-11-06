class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        for (int start = 0; start < n - k + 1; start++) {
            int num = nums[start];
            bool flag = true;
            for (int end = start + 1; end < start + k; end++) {
                if (nums[end] != num + 1) {
                    flag = false;
                    break;
                }
                num = nums[end];
            }
            flag ? res[start] = nums[start + k - 1] : res[start] = -1;
        }
        return res;
    }
};