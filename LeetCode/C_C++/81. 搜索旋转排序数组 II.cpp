class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto num : nums)
            if(num == target) return true;
        return false;
    }
};