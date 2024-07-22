class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt, cnt2;
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - i - 1];
            if (a > b) swap(a, b);
            cnt[b - a]++;
            cnt2[max(b, k - a)]++;
        }
        int res = n, sum = 0;
        for (int x = 0; x <= k; x++) {
            res = min(res, n / 2 - cnt[x] + sum);
            sum += cnt2[x];
        }
        return res;
    }
};
