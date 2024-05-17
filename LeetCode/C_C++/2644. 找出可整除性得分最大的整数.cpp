class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = nums.size(), m = divisors.size();
        vector<int> res(m);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[j] % divisors[i] == 0) {
                    res[i]++;
                }
            }
        }
        int ans = divisors[0], t = res[0];
        for(int i = 0; i < m; i++) {
            if(res[i] > t) {
                ans = divisors[i];
                t = res[i];
            } else if(res[i] == t && divisors[i] < ans) {
                ans = divisors[i];
            }
        }
        return ans;
    }
};