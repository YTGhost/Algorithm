class Solution {
public:
    vector<int> getPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return prefixSum;
    }
    bool check(vector<int>& prefixSum, int k, int t) {
        int l = 0, r = 0, n = prefixSum.size() - 1, cnt = 0;
        while(r <= n) {
            if(prefixSum[r] - prefixSum[l] > t) {
                l = r - 1;
                cnt++;
                if(cnt >= k) {
                    return false;
                }
            } else {
                r++;
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        vector<int> prefixSum = getPrefixSum(nums);
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0) + 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(prefixSum, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};