class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int> d(n + 1);
        d[len] = nums[0];
        for(int i = 1; i < n; i++) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int l = 1, r = len + 1;
                while(l < r) {
                    int mid = l + (r - l) / 2;
                    if (d[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                d[l] = nums[i];
            }
        }
        return len;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};

// AcWing基础班重做O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, 1);

        for(int i = 1; i <= size; i++)
            for(int j = 1; j < i; j++)
                if(nums[j-1] < nums[i-1]) dp[i] = max(dp[i], dp[j] + 1);
        int res = 0;
        for(int i = 1; i <= size; i++) res = max(res, dp[i]);
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        int dp[size] = {0};
        int maxLength = 1;
        dp[0] = 1;
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};