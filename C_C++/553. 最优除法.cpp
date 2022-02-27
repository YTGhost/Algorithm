class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string res = "";
        if(n == 1) return to_string(nums[0]);
        if(n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        if(n > 2) {
            res += to_string(nums[0]) + "/(";
            for(int i = 1; i < n; i++) {
                if(i != 1) res += "/";
                res += to_string(nums[i]);
            }
            res += ")";
        }
        return res;
    }
};