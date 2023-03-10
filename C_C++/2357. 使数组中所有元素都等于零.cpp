class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num : nums) {
            if(num > 0) {
                s.emplace(num);
            }
        }
        return s.size();
    }
};