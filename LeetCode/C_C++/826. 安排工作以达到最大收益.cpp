class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++) {
            nums[i] = pair<int, int>{difficulty[i], profit[i]};
        }
        sort(nums.begin(), nums.end());
        int maxVal = 0;
        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i].second);
            nums[i].second = maxVal;
        }
        function<int(int)> lower_bound = [&](int target) {
            int l = 0, r = n;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if (nums[mid].first >= target) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        int res = 0;
        for(int i = 0; i < m; i++) {
            int idx = lower_bound(worker[i] + 1) - 1;
            if(idx == -1) continue;
            res += nums[idx].second;
        }
        return res;
    }
};