class Solution {
public:
    bool check(vector<int>& nums, int t, int threshold) {
        int sum = 0;
        for(auto num : nums) {
            sum += ceil(1.0 * num / t);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1, end = 0;
        for(auto num : nums) {
            end = max(end, num);
        }
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(check(nums, mid, threshold)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};