class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        map<vector<int>, int> m;
        for(auto row : grid) {
            m[row]++;
        }
        for(int j = 0; j < n; j++) {
            vector<int> arr;
            for(int i = 0; i < n; i++) {
                arr.emplace_back(grid[i][j]);
            }
            if(m.find(arr) != m.end()) {
                res += m[arr];
            }
        }
        return res;
    }
};