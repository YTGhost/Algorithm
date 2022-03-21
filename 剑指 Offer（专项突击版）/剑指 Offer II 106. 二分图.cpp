class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i = 0; i < n; i++) {
            if(colors[i] != -1) continue;
            queue<int> q;
            colors[i] = 0;
            q.push(i);
            while(!q.empty()) {
                auto idx = q.front();
                q.pop();
                for(int j = 0; j < graph[idx].size(); j++) {
                    if(colors[graph[idx][j]] == -1) {
                        colors[graph[idx][j]] = 1 - colors[idx];
                        q.push(graph[idx][j]);
                    } else if(colors[graph[idx][j]] == colors[idx]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};