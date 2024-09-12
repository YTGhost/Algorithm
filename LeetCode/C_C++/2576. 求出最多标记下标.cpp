class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n / 2 + 1;
        function<bool(int)> check = [&](int target) {
            for (int i = 0; i < target; i++) {
                if (2 * nums[i] > nums[n - target + i]) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (l - 1) * 2;
    }
};