class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, pre = -1, res = 0;
        for(auto num : nums) {
            if(num <= pre) {
                sum = 0;
            }
            sum += num;
            pre = num;
            res = max(res, sum);

        }
        return res;
    }
};