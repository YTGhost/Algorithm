class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        unordered_set<int> st;
        for (auto num : nums) {
            if (st.count(num)) {
                res ^= num;
            } else {
                st.insert(num);
            }
        }
        return res;
    }
};