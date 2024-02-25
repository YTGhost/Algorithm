class Solution {
public:
    vector<int> p;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0; i < n; i++) p.push_back(i);
        int cnt = n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] && find(i) != find(j)) {
                    p[find(i)] = find(j);
                    cnt--;
                }
            }
        return cnt;
    }
};