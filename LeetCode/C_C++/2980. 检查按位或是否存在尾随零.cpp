class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = nums.size();
        for(auto num : nums) {
            even -= num % 2;
        }
        return even >= 2;
    }
};