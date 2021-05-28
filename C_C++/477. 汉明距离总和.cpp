class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < 30; i++) {
            int t = 0;
            for(int num : nums) {
                t += (num >> i) & 1;
            }
            res += t * (n - t);
        }
        return res;
    }
};