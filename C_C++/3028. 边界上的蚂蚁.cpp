class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n = nums.size();
        int t = 0, res = 0;
        for(auto num : nums) {
            t += num;
            if(t == 0) res++;
        }
        return res;
    }
};