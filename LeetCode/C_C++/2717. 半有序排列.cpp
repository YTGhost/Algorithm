class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int a, b, res;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                a = i;
            }
            if (nums[i] == n) {
                b = i;
            }
        }
        if (a < b) {
            res = a + n - b - 1;
        }
        if (a > b) {
            res = a + n - b - 2;
        }
        return res;
    }
};