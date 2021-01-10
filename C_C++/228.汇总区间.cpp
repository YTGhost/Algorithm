class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        if(!n) return res;
        int start = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1] + 1) {
                if(nums[i-1] == nums[start]) res.push_back(to_string(nums[start]));
                else {
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i;
            }
        }
        if(start == n-1) res.push_back(to_string(nums[n-1]));
        else res.push_back(to_string(nums[start]) + "->" + to_string(nums[n-1]));
        return res;
    }
};
