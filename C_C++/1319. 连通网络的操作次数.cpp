class Solution {
public:
    vector<int> p;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x]; 
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int res = 0;
        if(connections.size() < n-1) return -1;
        for(int i = 0; i < n; i++) p.push_back(i);
        for(auto connection : connections)
        {
            p[find(connection[0])] = find(connection[1]);
        }
        for(int i = 0; i < n; i++)
            if(p[i] == i) res++;
        return res-1;
    }
};