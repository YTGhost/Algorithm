class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int a = 0, b = nums.size();
        unordered_set<int> s;
        for(auto num : nums) {
            if(s.count(num)) {
                s.erase(num);
                a++;
                b -= 2;
            } else {
                s.insert(num);
            }
        }
        return vector<int>{a, b};
    }
};