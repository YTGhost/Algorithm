class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        for(auto t : adjacentPairs) {
            map[t[0]].push_back(t[1]);
            map[t[1]].push_back(t[0]);
        }
        vector<int> res(adjacentPairs.size() + 1);
        for(auto& [e, adj] : map ) {
            if(adj.size() == 1) {
                res[0] = e;
                break;
            }
        }
        res[1] = map[res[0]][0];
        for(int i = 2; i < adjacentPairs.size() + 1; i++) {
            auto& adj = map[res[i-1]];
            res[i] = res[i-2] == adj[0] ? adj[1] : adj[0];
        }
        return res;
    }
};