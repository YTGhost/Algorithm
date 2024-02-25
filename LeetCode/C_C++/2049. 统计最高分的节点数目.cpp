class Solution {
public:
    long maxScore = 0;
    int cnt = 0;
    vector<vector<int>> children;
    int n;
    int hash[100010];
    int dfs(int node) {
        long score = 1;
        int size = n - 1;
        for(int child : children[node]) {
            int t = hash[child] == 0x3f3f3f3f ? dfs(child) : hash[child];
            score *= t;
            size -= t;
        }
        if(node != 0) {
            score *= size;
        }
        if(score == maxScore) {
            cnt++;
        } else if(score > maxScore) {
            maxScore = score;
            cnt = 1;
        }
        hash[node] = n - size;
        return n - size;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        memset(hash, 0x3f, sizeof hash);
        children = vector<vector<int>>(n);
        for(int i = 0; i < n; i++) {
            int p = parents[i];
            if(p != -1) {
                children[p].push_back(i);
            }
        }
        dfs(0);
        return cnt;
    }
};