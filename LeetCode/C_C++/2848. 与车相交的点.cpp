class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int max_end = 0;
        for (auto item : nums) {
            max_end = max(max_end, item[1]);
        }
        vector<int> diff(max_end + 2);
        for (auto item : nums) {
            diff[item[0]]++;
            diff[item[1] + 1]--;
        }
        int res = 0, sum = 0;
        for (int val : diff) {
            sum += val;
            if (sum > 0) {
                res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> st;
        for (auto item : nums) {
            int start = item[0], end = item[1];
            for (int i = start; i <= end; i++) {
                st.insert(i);
            }
        }
        return st.size();
    }
};