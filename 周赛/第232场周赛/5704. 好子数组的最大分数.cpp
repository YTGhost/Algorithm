class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> h(n + 2, -1), l(n + 2), r(n + 2), stk(n + 2);
        for(int i = 1; i <= n; i++) h[i] = nums[i-1];
        int tt = 0;
        stk[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            while(h[stk[tt]] >= h[i]) tt--;
            l[i] = stk[tt];
            stk[++tt] = i;
        }
        tt = 0, stk[0] = n + 1;
        for(int i = n; i >= 1; i--)
        {
            while(h[stk[tt]] >= h[i]) tt--;
            r[i] = stk[tt];
            stk[++tt] = i;
        }
        k++;
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(l[i] < k && r[i] > k)
                res = max(res, (r[i] - l[i] - 1) * h[i]);
        return res;
    }
};