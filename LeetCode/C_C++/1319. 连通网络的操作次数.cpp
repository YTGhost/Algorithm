// 每日一题打卡
class Solution {
public:
    int p[100010];
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size()) return -1;
        for(int i = 0; i < n; i++) p[i] = i;
        for(auto connection : connections)
            p[find(connection[0])] = find(p[connection[1]]);
        int count = 0;
        for(int i = 0; i < n; i++) 
            if(p[i] == i) count++;
        return count - 1;
    }
};

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