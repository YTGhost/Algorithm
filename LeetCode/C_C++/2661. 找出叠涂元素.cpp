class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCnt(m), colCnt(n);
        int res;
        for(int i = 0; i < arr.size(); i++) {
            auto [a, b] = mp[arr[i]];
            rowCnt[a]++;
            colCnt[b]++;
            if(rowCnt[a] == n || colCnt[b] == m) {
                res = i;
                break;
            }
        }
        return res;
    }
};