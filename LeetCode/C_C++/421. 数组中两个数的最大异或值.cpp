class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int high_bit = maxNum ? 31 - __builtin_clz(maxNum) : -1;
        int res = 0, mask = 0;
        unordered_set<int> hash;
        for(int i = high_bit; i >= 0; i--) {
            hash.clear();
            mask |= 1 << i;
            int newRes = res | (1 << i);
            for(int num : nums) {
                num &= mask;
                if(hash.contains(newRes ^ num)) {
                    res = newRes;
                    break;
                }
                hash.insert(num);
            }
        }
        return res;
    }
};