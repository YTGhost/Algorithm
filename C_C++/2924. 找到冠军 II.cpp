class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < edges.size(); i++) {
            m[edges[i][1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(m[i] == 0) {
                res.push_back(i);
            }
        }
        return res.size() == 1 ? res[0] : -1;
    }
};