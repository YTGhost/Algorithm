class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxNum = nums[0], minNum = nums[0], res = 0;
        for(auto num : nums) {
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        for(auto num : nums) {
            if(num > minNum && num < maxNum) {
                res++;
            }
        }
        return res;
    }
};