class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        function<int(int)> getCnt = [&](int num) {
            int cnt = 0;
            while (num) {
                cnt += num & 1;
                num >>= 1;
            }
            return cnt;
        };
        for (int i = 0; i < n;) {
            int start = i;
            int cnt = getCnt(nums[i++]);
            while (i < n && cnt == getCnt(nums[i])) {
                i++;
            }
            sort(nums.begin() + start, nums.begin() + i);
        }
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};