class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for(int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        int res = n;
        for(auto &[_, arr] : pos) {
            int t = n - arr.back() + arr[0];
            for(int i = 1; i < arr.size(); i++) {
                t = max(t, arr[i] - arr[i - 1]);
            }
            res = min(res, t);
        }
        return res / 2;
    }
};