class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> mp;
        function<int(int)> dfs = [&](int i) {
            if (i == 1) {
                return 0;
            }
            if (mp.find(i) != mp.end()) {
                return mp[i];
            }
            int sum = 0;
            if (i % 2 == 0) {
                sum += dfs(i / 2) + 1;
            } else {
                sum += dfs((3 * i + 1) / 2) + 2;
            }
            mp[i] = sum;
            return sum;
        };
        for (int i = 1; i <= 1000; i++) {
            dfs(i);
        }
        int n = hi - lo + 1;
        vector<pair<int, int>> weights(n);
        for (int i = 0; i < n; i++) {
            weights[i] = {mp[lo + i], lo + i};
        }
        sort(weights.begin(), weights.end());
        return weights[k - 1].second;
    }
};