class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<bool> visit(n, false);
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        vector<long long> res(m, 0LL);
        for(int i = 0; i < n; i++) {
            q.push({nums[i], i});
        }
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int idx = queries[i][0], k = queries[i][1];
            if(!visit[idx]) {
                visit[idx] = true;
                sum -= (long long)nums[idx];
                cnt++;
            }
            if(k >= n - cnt) {
                break;
            }
            for(int j = 0; j < k; j++) {
                auto t = q.top();
                q.pop();
                if(visit[t.second]) {
                    j--;
                    continue;
                }
                sum -= (long long)t.first;
                visit[t.second] = true;
                cnt++;
            }
            res[i] = sum;
        }
        return res;
    }
};