class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for(auto num : nums1) s1.insert(num);
        for(auto num : nums2) s2.insert(num);
        return getResult(s1, s2);
    }

    vector<int> getResult(unordered_set<int>& s1, unordered_set<int>& s2) {
        if(s1.size() > s2.size()) return getResult(s2, s1);
        vector<int> res;
        for(auto num : s1) {
            if(s2.count(num)) {
                res.push_back(num);
            }
        }
        return res;
    }
};