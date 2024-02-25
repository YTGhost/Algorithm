class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first != b.first) return a.first < b.first;
        else {
            return a.second < b.second;
        }
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> t(n);
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += mat[i][j];
            }
            t[i].first = sum;
            t[i].second = i;
        }
        sort(t.begin(), t.end(), cmp);
        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = t[i].second;
        }
        return res;
    }
};