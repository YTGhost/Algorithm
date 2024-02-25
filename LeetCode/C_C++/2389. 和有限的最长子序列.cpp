class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> res(m), f(n+1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            f[i+1] = f[i] + nums[i];
        }
        for(int i = 0; i < m; i++) {
            int l = 0, r = n;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(f[mid] > queries[i]) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            res[i] = l;
        }
        return res;
    }
};