class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> degree(n);
        vector<vector<int>> near(n);
        vector<int> res;
        queue<int> q;
        for(auto edge : edges) {
            near[edge[0]].push_back(edge[1]);
            near[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }
        int remain = n;
        while(remain > 2) {
            int cnt = q.size();
            remain -= cnt;
            for(int i = 0; i < cnt; i++) {
                int cur = q.front();
                q.pop();
                for(auto t : near[cur]) {
                    if(--degree[t] == 1) {
                        q.push(t);
                    }
                }
            }
        }
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
        }
        return res;
    }
};