class Solution {
public:
    int getDist(int r, int c, int r0, int c0) {
        return abs(r - r0) + abs(c - c0);
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxSize = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<vector<int>>> bucket(maxSize+1);
        vector<vector<int>> res;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
            {
                vector<int> t = {i, j};
                int dist = getDist(i, j, r0, c0);
                bucket[dist].emplace_back(t);
            }
        for(int i = 0; i < maxSize+1; i++)
        {
            vector<vector<int>> t = bucket[i];
            for(int i = 0; i < t.size(); i++)
                res.emplace_back(t[i]);
        }
        return res;
    }
};