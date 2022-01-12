// 定长上升子序列 O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(3, INT_MAX);
        for(int i = 0; i < n; i++) {
            int t = nums[i];
            if(t > f[2]) return true;
            else if(t > f[1] && t < f[2]) f[2] = t;
            else if(t < f[1]) f[1] = t;
        }
        return false;
    }
};

// 最长上升子序列 贪心+二分 O(nlog(n))
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n + 1);
        f[0] = -2e9;
        int len = 0;
        for(int i = 0; i < n; i++) {
            int l = 0, r = len;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(f[mid] < nums[i]) l = mid;
                else r = mid - 1;
            }
            len = max(len, l + 1);
            f[l + 1] = nums[i];
        }
        return len >= 3;
    }
};