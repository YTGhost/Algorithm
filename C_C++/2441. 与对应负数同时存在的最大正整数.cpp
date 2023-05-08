class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = INT_MIN;
        unordered_set<int> s;
        for(auto num : nums) {
            if(s.count(-num)) {
                res = max(res, abs(num));
            }
            s.insert(num);
        }
        return res < 0 ? -1 : res;
    }
};