class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for (auto num : nums) {
            sum1 += num;
        }
        for (auto num : nums) {
            while (num) {
                sum2 += num % 10;
                num /= 10;
            }
        }
        return abs(sum1 - sum2);
    }
};