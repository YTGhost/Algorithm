class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0, minStock = *min_element(stock.begin(), stock.end());
        function<bool(int, int)> check = [&](int i, int cnt) {
            long long sum = budget;
            for(int j = 0; j < n; j++) {
                sum -= max((long long)cnt * composition[i][j] - stock[j], 0LL) * (long long)cost[j];
                if(sum < 0) {
                    return false;
                }
            }
            return true;
        };
        for(int i = 0; i < k; i++) {
            int l = 0, r = minStock + budget + 1;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(check(i, mid)) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            res = max(res, l - 1);
        }
        return res;
    }
};