class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> t(maxVal + 1);
        for(auto num : nums) {
            t[num] += num;
        }
        function<int(vector<int>&)> rob = [&](vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            nums[1] = max(nums[0], nums[1]);
            for(int i = 2; i < n; i++) {
                nums[i] = max(nums[i] + nums[i - 2], nums[i - 1]);
            }
            return nums[n - 1];
        };
        return rob(t);
    }
};

class Solution {
public:
    int rob(vector<int> &nums) {
        int size = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for(int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for(auto num: nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> sum(maxVal + 1);
        for(auto num: nums) {
            sum[num] += num;
        }
        return rob(sum);
    }
};