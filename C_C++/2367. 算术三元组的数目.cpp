class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> hash;
        for(auto num : nums) {
            hash.insert(num);
        }
        int res = 0;
        for(auto num : hash) {
            if(hash.count(num - diff) && hash.count(num + diff)) {
                res++;
            }
        }
        return res;
    }
};