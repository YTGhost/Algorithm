class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0, sum1 = 0, sum2 = 0;
        for (auto num : nums) {
            sum += num;
            if (num < 10) {
                sum1 += num;
            }
            if (num >= 10 && num <= 99) {
                sum2 += num;
            }
        } 
        if (2 * sum1 > sum || 2 * sum2 > sum) {
            return true;
        }
        return false;
    }
};