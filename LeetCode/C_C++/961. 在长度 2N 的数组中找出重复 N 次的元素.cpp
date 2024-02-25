class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto num : nums) {
            if(hash.count(num)) {
                return num;
            }
            hash.insert(num);
        }
        return -1;
    }
};