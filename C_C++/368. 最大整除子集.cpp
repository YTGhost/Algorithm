class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        for(int i = 0; i < n; i++) {
            int len = 1, pre = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(f[j] + 1 > len) {
                        len = f[j] + 1;
                        pre = j;
                    }
                }
            }
            f[i] = len;
            g[i] = pre;
        }
        int max = -1, idx = -1;
        for(int i = 0; i < n; i++) {
            if(f[i] > max) {
                max = f[i];
                idx = i;
            }
        }
        vector<int> res;
        while(res.size() != max) {
            res.emplace_back(nums[idx]);
            idx = g[idx];
        }
        return res;
    }
};