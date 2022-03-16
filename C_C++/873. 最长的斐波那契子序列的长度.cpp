class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> hash;
        for(int i = 0; i < n; i++) {
            hash[arr[i]] = i;
        }
        vector<vector<int>> f(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                f[i][j] = 2;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int diff = arr[j] - arr[i];
                if(hash.count(diff)) {
                    int idx = hash[diff];
                    if(idx < i) {
                        f[i][j] = max(f[i][j], f[idx][i] + 1);
                    }
                }
                res = max(res, f[i][j]);
            }
        }
        return res > 2 ? res : 0;
    }
};