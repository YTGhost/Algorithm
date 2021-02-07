// 时间复杂度O(n)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n-1; i++)
        {
            int x = nums[i], y = nums[i+1];
            if(x > y) {
                res++;
                if(res > 1) return false;
                if(i > 0 && y < nums[i-1]) nums[i+1] = x;
            }
        }
        return true;
    }
};

// 最长不下降子序列，时间复杂度:O(nlogn)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n+1, 1);
        vector<int> q(n+1, 0);
        q[0] = INT_MIN;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int l = 0, r = res;
            while(l < r)
            {
                int mid = l + r + 1 >> 1;
                if(q[mid] <= nums[i]) l = mid;
                else r = mid - 1;
            }
            res = max(res, l+1);
            q[l+1] = nums[i];
        }
        return res >= n-1;
    }
};