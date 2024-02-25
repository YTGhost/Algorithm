class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pre(n+1);
        for(int i = 1; i <= n; i++)
            pre[i] = nums[i-1] + pre[i-1];
        int res = 1;
        for(int i = 1; i < n; i++)
        {
            int l = 0, r = i;
            while(l < r)
            {
                long long mid = l + r >> 1;
                long long cnt = (i - mid + 1) * nums[i] - (pre[i+1] - pre[mid]);
                if(k >= cnt) r = mid;
                else l = mid + 1;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};