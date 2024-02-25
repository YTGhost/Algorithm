class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), res = -1;
        vector<int> mx(82);
        for(auto num : nums) {
            int sum = 0, x = num;
            while(x) {
                sum += x % 10;
                x /= 10;
            }
            if(mx[sum] != 0) {
                res = max(res, mx[sum] + num);
            }
            mx[sum] = max(mx[sum], num);
        }
        return res;
    }
};