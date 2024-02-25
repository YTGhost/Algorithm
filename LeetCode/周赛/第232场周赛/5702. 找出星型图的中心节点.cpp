class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> cnt(n+1, 0);
        for(auto edge : edges)
        {
            cnt[edge[0]]++;
            cnt[edge[1]]++;
        }
        int res;
        for(int i = 1; i < n+1; i++)
            if(cnt[i] == n-1) res = i;
        return res;
    }
};