class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(grid[i][res] == 1) {
                res = i;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    s.insert(j);
                }
            }
        }
        int res;
        for(int i = 0; i < n; i++) {
            if(s.count(i) == 0) {
                res = i;
            }
        }
        return res;
    }
};