class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = INT_MIN, t = INT_MAX;
        for(auto num : nums) {
            if(abs(num) < t) {
                t = abs(num);
                res = num;
            } else if(abs(num) == t) {
                res = max(res, num);
            }
        }
        return res;
    }
};