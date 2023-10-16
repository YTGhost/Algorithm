class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorSum = 0;
        for(auto num : nums) {
            xorSum ^= num;
        }
        int lowbit = xorSum & -xorSum;
        vector<int> res(2);
        for(auto num : nums) {
            res[(num & lowbit) != 0] ^= num;
        }
        return res;
    }
};