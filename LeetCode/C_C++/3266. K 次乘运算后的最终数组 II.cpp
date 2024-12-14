class Solution {
public:
    const int MOD = 1e9 + 7;
    long long pow(long long x, int k) {
        long long res = 1;
        for (; k; k /= 2) {
            if (k % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        int n = nums.size();
        int maxVal = -1;
        vector<pair<long long, int>> h(n);
        for (int i = 0; i < n; i++) {
            h[i] = {nums[i], i};
            maxVal = max(maxVal, nums[i]);
        }
        ranges::make_heap(h, greater<>());
        for (; k && h[0].first < maxVal; k--) {
            ranges::pop_heap(h, greater<>());
            h.back().first *= multiplier;
            ranges::push_heap(h, greater<>());
        }
        ranges::sort(h);
        for (int i = 0; i < n; i++) {
            auto& [x, idx] = h[i];
            nums[idx] = x % MOD * pow(multiplier, k / n + (i < k % n)) % MOD;
        }
        return nums;
    }
};