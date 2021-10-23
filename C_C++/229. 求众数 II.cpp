// 哈希表
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
        }
        int k = nums.size() / 3;
        vector<int> res;
        for(auto item : m) {
            if(item.second > k) {
                res.push_back(item.first);
            }
        }
        return res;
    }
};